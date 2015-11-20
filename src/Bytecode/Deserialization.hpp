#ifndef __DESERIALIZATION_HPP__
#define __DESERIALIZATION_HPP__

#include <string>

class BytecodeStream;
class Object;
struct Instruction;

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
        Deserialization();
        ~Deserialization();

        void deserializeByteCode(const string& fileName);

    private:

        BytecodeStream* m_stream;

        void nextByteMatchType(const serializableType_t& type);
        Instruction readInstruction();
        //Object* readNull();
        //Object* readBoolean();
        //Object* readSymbol();
        //Object* readNumber();
        //Object* readPair();
        //Object* readSequence();
};

#endif

