#include "BuiltIn.hpp"

#include "BuiltInError.hpp"
#include "../../Objects/SchemePair.hpp"
#include "../../Objects/SchemeNumber.hpp"
#include "../../Objects/SchemeBool.hpp"
#include "../../Objects/SchemeSymbol.hpp"
#include "../../Objects/SchemeNull.hpp"
#include <iostream>
#include <functional>
#include <sstream>
#include <typeinfo>
#include <string>

using std::plus;
using std::minus;
using std::multiplies;
using std::divides;
using std::equal_to;
using std::greater;
using std::less;
using std::greater_equal;
using std::less_equal;
using std::string;

FILE* BUILTIN_inFile = NULL;
FILE* BUILTIN_outFile = stdout;

void builtInVerifyCondition(bool condition,const string& message) {
    if(!condition) {
        throw BuiltInError(message);
    }
}

// Kontrola - jedna se opravdu o danu typ
template<class T>
T* builtInVerifyType(SchemeObject* arg, string message) {
    T* tmpArg= dynamic_cast<T*>(arg);

    if (!tmpArg) {
        throw BuiltInError(message);
    }
    return tmpArg;
}
static void builtInVerifyNumberArg(BuiltInArgs& args, unsigned number, const string& name) {
    builtInVerifyCondition(args.size() == number, name + ": Wrong number of arguments");
}

template<class ComparisonOperation>
static SchemeObject* builtInComparisonOperation(string name, BuiltInArgs& args, ComparisonOperation func){
    string errorMsg = "Comparison operation " + name + " expect number";
    builtInVerifyCondition(args.size() > 0, "expet arguments");
    SchemeNumber* firstArg = builtInVerifyType<SchemeNumber>(args[0],errorMsg);

    for (BuiltInArgs::iterator argIterator = args.begin() + 1; argIterator != args.end(); ++argIterator) {
        SchemeNumber* nextArgument = builtInVerifyType<SchemeNumber>(*argIterator,errorMsg);
        if (func(firstArg->getValue(), nextArgument->getValue())) {
            firstArg = nextArgument;
        } else {
            return new SchemeBool(false);
        }
    }
    return new SchemeBool(true);
}

// Volba aritmeticke operace
template<class ArithmeticOperation>
static SchemeObject* builtInArithmeticOperation(string name, BuiltInArgs& args, ArithmeticOperation func) {
    string errorMsg = "Arithmetic operation " + name + " expect number";
    builtInVerifyCondition(args.size() > 0, errorMsg);
    SchemeNumber* firstArg = builtInVerifyType<SchemeNumber>(args[0], errorMsg);
    int result = firstArg->getValue();

    for (BuiltInArgs::iterator argIterator = args.begin() + 1 ; argIterator != args.end(); ++argIterator) {
        SchemeNumber* nextArgument = builtInVerifyType<SchemeNumber>(*argIterator, errorMsg);
        result = func(result, nextArgument->getValue());
    }
    return new SchemeNumber(result);
}

static SchemeObject* builtInPlus(BuiltInArgs& args) {
   return builtInArithmeticOperation("+", args, plus<int>());
}
static SchemeObject* builtInMinus(BuiltInArgs& args) {
    return builtInArithmeticOperation("-", args, minus<int>());
}
static SchemeObject* builrInMul(BuiltInArgs& args) {
   return builtInArithmeticOperation("*", args, multiplies<int>());
}
static SchemeObject* builrInQuot(BuiltInArgs& args) {
    return builtInArithmeticOperation("/", args, divides<int>());
}

static SchemeObject* builtInCar(BuiltInArgs& args) {
    builtInVerifyNumberArg(args, 1, "car");
    string errorMsg = "car expect pair";
    SchemePair *pair = builtInVerifyType<SchemePair>(args[0],errorMsg);
    return pair->getFirst();
}
static SchemeObject* builtInCdr(BuiltInArgs& args) {
    builtInVerifyNumberArg(args, 1, "cdr");
    string errorMsg = "cdr expect pair";
    SchemePair *pair = builtInVerifyType<SchemePair>(args[0],errorMsg);
    return pair->getSecond();
}
static SchemeObject* builtInCadr(BuiltInArgs& args) {
    builtInVerifyNumberArg(args, 1, "cadr");
    string errorMsg = "cadr expect pair";
    SchemePair *pair = builtInVerifyType<SchemePair>(args[0],errorMsg);
    SchemePair *next_pair = builtInVerifyType<SchemePair>(pair->getSecond(),errorMsg + "in second part of pair");
    return next_pair->getFirst();
}
static SchemeObject* builtInCons(BuiltInArgs& args) {
    builtInVerifyNumberArg(args, 2, "cons");
    return new SchemePair(args[0], args[1]);
}

/*------------Predicates-----------*/
static SchemeObject* builtInIsNumber(BuiltInArgs& args) {
    builtInVerifyNumberArg(args, 1, "number?");
    SchemeNumber* sn = dynamic_cast<SchemeNumber*>(args[0]);
    return new SchemeBool(sn != 0);
}
static SchemeObject* builtInIsSymbol(BuiltInArgs& args) {
    builtInVerifyNumberArg(args, 1, "symbol?");
    SchemeSymbol* ss= dynamic_cast<SchemeSymbol*>(args[0]);
    return new SchemeBool(ss != 0);
}
static SchemeObject* builtInIsZero(BuiltInArgs& args) {
    builtInVerifyNumberArg(args, 1, "zero?");
    SchemeNumber* sn= dynamic_cast<SchemeNumber*>(args[0]);
    return new SchemeBool(sn && ( sn->getValue() == 0));
}
static SchemeObject* builtInIsPair(BuiltInArgs& args) {
    builtInVerifyNumberArg(args, 1, "pair?");
    SchemePair* sp= dynamic_cast<SchemePair*>(args[0]);
    return new SchemeBool(sp != 0);
}
static SchemeObject* builtInIsNull(BuiltInArgs& args) {
    builtInVerifyNumberArg(args, 1, "null?");
    SchemeNull* sn= dynamic_cast<SchemeNull*>(args[0]);
    return new SchemeBool(sn != 0);
}

static bool equalObjects(const SchemeObject *first, const SchemeObject *second) {
    if (first == second) {
        return true;
    } else if (typeid(*first) != typeid(*second)) {
        return false;
    } else {
        return first->equalsTo(*second);
    }
}
/*---same objects or same types with same values--*/
static SchemeObject* builtInIsEqual(BuiltInArgs& args) {
    builtInVerifyNumberArg(args, 2, "eq?");
    SchemeObject* first = args[0];
    SchemeObject* second = args[1];

    if (dynamic_cast<SchemePair*>(first) && dynamic_cast<SchemePair*>(second)) {
        return new SchemeBool(first == second);
    } else {
        return new SchemeBool(equalObjects(first, second));
    }
}

/*------Comparison function----*/

// compares only numbers, regardless of type.
static SchemeObject* builtInEqTo(BuiltInArgs& args) {
    return builtInComparisonOperation("=", args, equal_to<int>());
}
static SchemeObject* builtInGreater(BuiltInArgs& args) {
    return builtInComparisonOperation(">", args, greater<int>());
}
static SchemeObject* builtInLess(BuiltInArgs& args) {
    return builtInComparisonOperation("<", args, less<int>());
}
static SchemeObject* builtInGreaterEq(BuiltInArgs& args) {
    return builtInComparisonOperation(">=", args, greater_equal<int>());
}
static SchemeObject* builtInLessEq(BuiltInArgs& args) {
    return builtInComparisonOperation("<=", args, less_equal<int>());
}

static SchemeObject* builtInList(BuiltInArgs& args) {
    SchemeObject *list = new SchemeNull();

    for (BuiltInArgs::reverse_iterator argIterator = args.rbegin(); argIterator != args.rend(); ++argIterator) {
        list = new SchemePair(*argIterator, list);
    }
    return list;
}

static SchemeObject* builtInWrite(BuiltInArgs& args) {
    string output;

    for (BuiltInArgs::const_iterator it = args.begin(); it != args.end(); it++) {
        output += (*it)->print();
        if (it != args.end() - 1) {
            output += " ";
        }
    }
    fputs(output.c_str(), BUILTIN_outFile);
    return new SchemeNull();
}

static SchemeObject* builtInRead(BuiltInArgs& args) {
    if (!BUILTIN_inFile) {
        throw BuiltInError("There is no input file.");
    }
    (void) args;
    // TODO: Implement read line from open file
    return new SchemeNull();
}

static SchemeObject* builtInNewLine(BuiltInArgs& args) {
    (void) args;
    string output = "\n";
    fputs(output.c_str(), BUILTIN_outFile);
    return new SchemeNull();
}

void setBuiltInOutFile(FILE* file) {
    if (file) {
        BUILTIN_outFile = file;
    }
}

void setBuiltInInFile(FILE* file) {
    if (file) {
        BUILTIN_inFile = file;
    }
}

void resetFiles() {
    BUILTIN_inFile = NULL;
    BUILTIN_outFile = stdout;
}

BuiltInMap mapOfAllBuiltIns() {
    BuiltInMap functions;

    functions["+"] = builtInPlus;
    functions["-"] = builtInMinus;
    functions["*"] = builrInMul;
    functions["/"] = builrInQuot;

    functions["car"] = builtInCar;
    functions["cdr"] = builtInCdr;
    functions["cadr"] = builtInCadr;
    functions["cons"] = builtInCons;

    functions["number?"] = builtInIsNumber;
    functions["symbol?"] = builtInIsSymbol;
    functions["zero?"] = builtInIsZero;
    functions["pair?"] = builtInIsPair;
    functions["null?"] = builtInIsNull;
    functions["eq?"] = builtInIsEqual;

    functions["="] = builtInEqTo;
    functions[">"] = builtInGreater;
    functions["<"] = builtInLess;
    functions[">="] = builtInGreaterEq;
    functions["<="] = builtInLessEq;

    functions["list"] = builtInList;

    functions["write"] = builtInWrite;
    functions["newline"] = builtInNewLine;
    functions["read"] = builtInRead;

    return functions;
}
