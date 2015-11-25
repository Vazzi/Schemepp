#ifndef __DESERIALIZATION_HPP__
#define __DESERIALIZATION_HPP__

#include <string>

class BytecodeStream;
class BasicObject;
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

        void deserializeByteCode(const string& fileName);

    private:

        BytecodeStream* m_stream;

        void nextByteMatchType(const serializableType_t& type);
        Instruction readInstruction();
        BasicObject* readNull();
        BasicObject* readBoolean();
        BasicObject* readSymbol();
        BasicObject* readNumber();
        BasicObject* readPair();
        BasicObject* readSequence();
        BasicObject* readBasicObject();
        string readString();
};

#endif
