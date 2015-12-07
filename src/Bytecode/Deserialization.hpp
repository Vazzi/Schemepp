#ifndef __DESERIALIZATION_HPP__
#define __DESERIALIZATION_HPP__

#include <string>

class BytecodeStream;
class SchemeObject;
class SchemeCodeObject;
struct Instruction;

using std::string;

enum serializableType_t {
    TypeNull = '0',
    TypeBoolean = 'b',
    TypeString = 's',
    TypeSymbol = 'S',
    TypeNumber = 'n',
    TypePair = 'p',
    TypeInstr = 'i',
    TypeSequence = '[',
    TypeCodeobject = 'c'
};

class Deserialization {
    public:
        Deserialization();
        ~Deserialization();

        SchemeCodeObject* deserializeByteCode(const string& fileName);

    private:
        BytecodeStream* m_stream;

        void nextByteMatchType(const serializableType_t& type);
        Instruction readInstruction();
        SchemeObject* readNull();
        SchemeObject* readBoolean();
        SchemeObject* readSymbol();
        SchemeObject* readNumber();
        SchemeObject* readPair();
        SchemeObject* readBasicObject();
        SchemeCodeObject* readCodeObject();
        string readString();
};

#endif

