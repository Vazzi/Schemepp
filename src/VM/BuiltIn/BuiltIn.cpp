#include "BuiltIn.hpp"
#include "Objects/SchemePair.hpp"

// TODO: Define and implement built-in functions
// car, cdr, +, -, ...

SchemeObject* builtInPlus(BuiltInArgs& args){
    // TODO
}
SchemeObject* builtInMinus(BuiltInArgs& args){
    // TODO
}
SchemeObject* builrInMul(BuiltInArgs& args){
    // TODO
}
SchemeObject* builrInQuot(BuiltInArgs& args){
    // TODO
}
SchemeObject* builtInCar(BuiltInArgs& args){
    // TODO
}
SchemeObject* builtInCdr(BuiltInArgs& args){
    // TODO
}
SchemeObject* builtInCons(BuiltInArgs& args){
    // TODO: verifying
    return new SchemePair(args[0],args[1]);
}
BuiltInMap mapOfAllBuiltIns() {
    BuiltInMap functions;

    functions["+"] = builtInPlus;
    functions["-"] = builtInMinus;
    functions["*"] = builrInMul;
    functions["/"] = builrInQuot;
    
    functions["car"] = builtInCar;
    functions["cdr"] = builtInCdr;   
    functions["cons"] = builtInCons;
   
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
