#ifndef __DESERIALIZATION_HPP__
#define __DESERIALIZATION_HPP__

#include <string>

class BytecodeStream;

using std::string;

enum serializableType_t {
    Null = '0',
    Boolean = 'b',
    String = 's',
    Symbol = 'S',
    Number = 'n',
    Pair = 'p',
    Instr = 'i',
    Sequence = '[',
    Codeobject = 'c'
};

class Deserialization {
    public:
        static void deserializeByteCode(const string& fileName);

    private:
        static void nextByteMatchType(BytecodeStream& stream,
                const serializableType_t& type);
};

#endif

