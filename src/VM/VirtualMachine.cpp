#include "VirtualMachine.hpp"

#include "../Objects/SchemeCodeObject.hpp"
#include "../Objects/SchemeBool.hpp"
#include "../Objects/SchemeFunction.hpp"
#include "Environment.hpp"
#include "BuiltIn/BuiltIn.hpp"
#include "BuiltIn/BuiltInError.hpp"
#include "BuiltIn/BuiltInFunction.hpp"
#include "VirtualMachineError.hpp"
#include <cassert>
#include <cstdio>

VirtualMachine::VirtualMachine() {
    m_currFrame.codeObject = 0;
    m_currFrame.pc = 0;
    m_currFrame.env = this->createGlobalEnvironment();
}

VirtualMachine::~VirtualMachine() {
    delete m_currFrame.env;
}


void VirtualMachine::run(SchemeCodeObject* codeObject) {
    if (codeObject == NULL) {
        return;
    }

    // Set current frame
    m_currFrame.codeObject = codeObject;
    m_currFrame.pc = 0;

    while(true) {
        // Get instruction
        Instruction instr;
        if (this->getNextInstruction(instr)) {
            m_currFrame.pc++;
        } else {
            break; // Last instruction, we are done
        }
        // Evaluate instruction
        this->evalInstruction(instr);
    }
}

Environment* VirtualMachine::createGlobalEnvironment() {
    Environment* env = new Environment();

    // Define all built in functions
    BuiltInMap builtIns = mapOfAllBuiltIns();
    for (BuiltInMap::const_iterator it = builtIns.begin();
            it != builtIns.end(); ++it) {
        SchemeObject* func = new BuiltInFunction(it->first, it->second);
        env->defineVariable(it->first, func);
    }

    return env;
}

bool VirtualMachine::getNextInstruction(Instruction& instr) const {
    if (m_currFrame.pc >= m_currFrame.codeObject->instructions.size()) {
        if (m_frameStack.size() == 0) {
            return false;
        } else {
            throw VirtualMachineError("Code ended prematurely");
        }
    } else {
        instr = m_currFrame.codeObject->instructions[m_currFrame.pc];
    }
    return true;
}

void VirtualMachine::evalInstruction(const Instruction& instr) {
    switch (instr.opCode) {
        case OP_CONST:
            this->evalConstOP(instr.arg);
            break;
        case OP_LOADVAR:
            this->evalLoadVarOP(instr.arg);
            break;
        case OP_STOREVAR:
            this->evalStoreVarOP(instr.arg);
            break;
        case OP_DEFVAR:
            this->evalDefVarOP(instr.arg);
            break;
        case OP_FUNCTION:
            this->evalFunctionOP(instr.arg);
            break;
        case OP_POP:
            this->evalPopOP();
            break;
        case OP_JUMP:
            this->evalJumpOP(instr.arg);
            break;
        case OP_FJUMP:
            this->evalFJumpOP(instr.arg);
            break;
        case OP_RETURN:
            this->evalReturnOP();
            break;
        case OP_CALL:
            this->evalCallOP(instr.arg);
            break;
        case OP_INVALID:
        default:
            char *err = new char;
            sprintf(err, "Invalid instruction operation code 0x%02X", instr.opCode);
            string text = string(err);
            throw VirtualMachineError(text);
    }
}

void VirtualMachine::evalConstOP(const unsigned int& instrArg) {
    assert(instrArg < m_currFrame.codeObject->constants.size()
            && "Constant index out of bounds");

    SchemeObject* value = m_currFrame.codeObject->constants[instrArg];
    m_valuesStack.push(value);
}

void VirtualMachine::evalLoadVarOP(const unsigned int& instrArg) {
    assert(instrArg < m_currFrame.codeObject->variableNames.size()
            && "Variables name index out of bounds");

    string name = m_currFrame.codeObject->variableNames[instrArg];
    SchemeObject* value = m_currFrame.env->getVariable(name);
    if (value == 0) {
        char *err = new char;
        sprintf(err, "Invalid variable %s", name.c_str());
        string text = string(err);
        throw VirtualMachineError(text);
    }
    m_valuesStack.push(value);
}

void VirtualMachine::evalStoreVarOP(const unsigned int& instrArg) {
    assert(!m_valuesStack.empty() && "Values stack is empty");
    assert(instrArg < m_currFrame.codeObject->variableNames.size()
            && "Variables name index out of bounds");

    SchemeObject* value = m_valuesStack.top();
    m_valuesStack.pop();
    string name = m_currFrame.codeObject->variableNames[instrArg];
    SchemeObject* variable = m_currFrame.env->setVariable(name, value);
    if (variable == 0) {
        char *err = new char;
        sprintf(err, "Invalid variable %s", name.c_str());
        string text = string(err);
        throw VirtualMachineError(text);
    }
}

void VirtualMachine::evalDefVarOP(const unsigned int& instrArg) {
    assert(!m_valuesStack.empty() && "Values stack is empty");
    assert(instrArg < m_currFrame.codeObject->variableNames.size()
            && "Variables name index out of bounds");

    SchemeObject* value = m_valuesStack.top();
    m_valuesStack.pop();
    string name = m_currFrame.codeObject->variableNames[instrArg];
    m_currFrame.env->defineVariable(name, value);
}

void VirtualMachine::evalFunctionOP(const unsigned int& instrArg) {
    assert(instrArg < m_currFrame.codeObject->constants.size()
            && "Constant index out of bounds");

    SchemeObject* value = m_currFrame.codeObject->constants[instrArg];
    SchemeCodeObject* func = dynamic_cast<SchemeCodeObject*>(value);
    m_valuesStack.push(new SchemeFunction(func, m_currFrame.env));
}

void VirtualMachine::evalPopOP() {
    if (!m_valuesStack.empty()) {
        m_valuesStack.pop();
    }
}

void VirtualMachine::evalJumpOP(const unsigned int& instrArg) {
    m_currFrame.pc = instrArg;
}

void VirtualMachine::evalFJumpOP(const unsigned int& instrArg) {
    assert(!m_valuesStack.empty() && "Values stack is empty");

    SchemeBool* predicate = dynamic_cast<SchemeBool*>(m_valuesStack.top());
    m_valuesStack.pop();
    if (predicate && !predicate->getValue()) {
        m_currFrame.pc = instrArg;
    }
}

void VirtualMachine::evalReturnOP() {
    assert(!m_frameStack.empty() && "Frame stack is empty");

    m_currFrame = m_frameStack.top();
    m_frameStack.pop();
}

void VirtualMachine::evalCallOP(const unsigned int& instrArg) {
    SchemeObject* function = m_valuesStack.top();
    m_valuesStack.pop();
    vector<SchemeObject*> arguments; // Arguments of the function

    // Count of arguments is in argument of the instruction
    // Getting the arguments from the stack
    for (unsigned int i = 0; i < instrArg; i++) {
        arguments.push_back(m_valuesStack.top());
        m_valuesStack.pop();
    }
    reverse(arguments.begin(), arguments.end());

    // Evaluate function
    if (BuiltInFunction* func = dynamic_cast<BuiltInFunction*>(function)) {
        // Built in function
        try {
            SchemeObject* returnValue = func->evaluate(arguments);
            m_valuesStack.push(returnValue);
        } catch (BuiltInError& err) {
            throw VirtualMachineError(err.what());
        }
    } else if (SchemeFunction* func = dynamic_cast<SchemeFunction*>(function)) {
        // Function from code
        // Check if the arguments count is right
        if (arguments.size() != func->codeObject->args.size()) {
            char *err = new char;
            sprintf(err, "Calling function %s with %ld arguments, needed %ld arguments",
                    func->print().c_str(),
                    arguments.size(),
                    func->codeObject->args.size());
            throw VirtualMachineError(string(err));
        }

        // Define environment
        Environment* funcEnv = new Environment(func->env);
        for (unsigned int i = 0; i < arguments.size(); i++) {
            string name = func->codeObject->args[i];
            SchemeObject* value = arguments[i];
            funcEnv->defineVariable(name, value);
        }

        // Create new frame for function
        m_frameStack.push(m_currFrame);
        ExecutionFrame funcFrame;
        funcFrame.codeObject = func->codeObject;
        funcFrame.pc = 0;
        funcFrame.env = funcEnv;
        m_currFrame = funcFrame;
    } else {
        // There is no function
        throw VirtualMachineError("Calling of unknown function");
    }
}
