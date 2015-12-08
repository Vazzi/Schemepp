#include "BuiltIn.hpp"
#include "BuiltInError.hpp"
#include "Objects/SchemePair.hpp"
#include "Objects/SchemeNumber.hpp"
#include <iostream>
#include <functional>

using std::plus;
using std::minus;
using std::multiplies;
using std::divides;
// TODO: Define and implement built-in functions
// car, cdr, +, -, ...

void builtInVerify(bool condition, const string& message){
    if(!condition){
        throw BuiltInError(message);
    }
}

// Kontrola - jedna se opravdu o danu typ
template<class T>
T* builtInVerifyType(SchemeObject* arg, string message){
    T* tmpArg= dynamic_cast<T*>(arg);
    
    if(!tmpArg){
        throw BuiltInError(message);
    }
    return tmpArg;
}

// Volba aritmeticke operace
template<class ArithmeticOperation>
static SchemeObject* builtInArithmeticOperation(string name, BuiltInArgs& args, ArithmeticOperation func){
    string errorMsg = "Arithmetic operation " + name + " expect number";  
    builtInVerify(args.size() > 0, errorMsg);  
    SchemeNumber* firstArg = builtInVerifyType<SchemeNumber>(args[0],errorMsg);    
    int result = firstArg->getValue();
    
    for(BuiltInArgs::iterator argIterator = args.begin() + 1 ; argIterator != args.end(); ++argIterator){
        SchemeNumber* nextArgument= builtInVerifyType<SchemeNumber>(*argIterator,errorMsg);
        result = func(result, nextArgument->getValue());
    }
    return new SchemeNumber(result);

}

static SchemeObject* builtInPlus(BuiltInArgs& args){
   return builtInArithmeticOperation("+", args, plus<int>());
}
static SchemeObject* builtInMinus(BuiltInArgs& args){
    return builtInArithmeticOperation("-", args, minus<int>());
}
static SchemeObject* builrInMul(BuiltInArgs& args){
   return builtInArithmeticOperation("*", args, multiplies<int>());
}
static SchemeObject* builrInQuot(BuiltInArgs& args){
    return builtInArithmeticOperation("/", args, divides<int>());
}
static SchemeObject* builtInCar(BuiltInArgs& args){
    // TODO
}
static SchemeObject* builtInCdr(BuiltInArgs& args){
    // TODO
}
static SchemeObject* builtInCons(BuiltInArgs& args){
    // TODO: verifying
    return new SchemePair(args[0],args[1]);
}
BuiltInMap mapOfAllBuiltIns() {
    BuiltInMap functions;

    functions["+"] = builtInPlus;
    functions["-"] = builtInMinus;   
    functions["*"] = builrInMul;
    functions["/"] = builrInQuot;
    
    /*
    functions["car"] = builtInCar;
    functions["cdr"] = builtInCdr;   
    functions["cons"] = builtInCons;
   */
    
    // TODO: Map built-in functions   
    /*        
        functions['eq?'] = builtInEq;
        functions['eqv?'] = builtInEqv;
        functions['='] = builtInEqTo;
        functions['>='] = builrInGreaterEq;
        functions['<='] = builrInLessEq;
        functions['>'] = builrInGreater;
        functions['<'] = builrInLess;

        functions['number?'] = builrInNumber;
        functions['symbol?'] = builrInSymbol;
        functions['zero?'] = builrInZero;
        functions['pair?'] = builrInPair;
        functions['null?'] = builrInNull;  

        functions['list'] = builrInList;
    */
    
    return functions;
}
