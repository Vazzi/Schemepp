#ifndef __DESERIALIZATION_HPP__
#define __DESERIALIZATION_HPP__

#include <string>

class BytecodeStream;
class SchemeBasicObject;
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
        SchemeBasicObject* readNull();
        SchemeBasicObject* readBoolean();
        SchemeBasicObject* readSymbol();
        SchemeBasicObject* readNumber();
        SchemeBasicObject* readPair();
        SchemeBasicObject* readBasicObject();
        SchemeCodeObject* readCodeObject();
        string readString();
};

#endif

