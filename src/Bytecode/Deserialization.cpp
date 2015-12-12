#include "Deserialization.hpp"
#include "BytecodeStream.hpp"
#include "Bytecode.hpp"
#include "DeserializationError.hpp"
#include "../Objects/SchemeObject.hpp"
#include "../Objects/SchemeNull.hpp"
#include "../Objects/SchemeBool.hpp"
#include "../Objects/SchemeNumber.hpp"
#include "../Objects/SchemePair.hpp"
#include "../Objects/SchemeSymbol.hpp"
#include "../Objects/SchemeCodeObject.hpp"
#include <cstdio>

const unsigned INIT_WORD = 0x00010B0B;

Deserialization::Deserialization() {
    // empty
}

Deserialization::~Deserialization() {
    delete m_stream;
}

// Deserialize file with byte code
SchemeCodeObject* Deserialization::deserializeByteCode(const string& fileName) {

    m_stream = new BytecodeStream(fileName.c_str());

    unsigned int initWord = m_stream->readWord();
    if (initWord != INIT_WORD) {
        throw DeserializationError("Invalid bytecode. First word is not correct.");
    }

    nextByteMatchType(TypeCodeobject);
    return this->readCodeObject();
}

// Throw exception if next byte in stream does not match type
void Deserialization::nextByteMatchType(const serializableType_t& type) {
    unsigned char byte = m_stream->readByte();
    if (byte != type) {
        char *err = new char;
        sprintf(err, "Expected type %c and got %c", type, byte);
        string text = string(err);
        throw DeserializationError(text);
    }
}

Instruction Deserialization::readInstruction() {
    nextByteMatchType(TypeInstr);
    unsigned int wordData = m_stream->readWord();
    // Instruction bits first two from left
    // Argument the rest of the word last 6 bits
    Instruction inst = Instruction(wordData >> 24, wordData & 0xFFFFFF);
    return inst;
}

SchemeObject* Deserialization::readNull() {
    return new SchemeNull();
}

string Deserialization::readString() {
    nextByteMatchType(TypeString);
    unsigned length = m_stream->readWord();
    return m_stream->readString(length);
}

SchemeObject* Deserialization::readBoolean() {
    unsigned char value = m_stream->readByte();
    return new SchemeBool(value == 1);
}

SchemeObject* Deserialization::readSymbol() {
    string str = this->readString();
    return new SchemeSymbol(str);
}

SchemeObject* Deserialization::readNumber() {
    unsigned int word = m_stream->readWord();
    return new SchemeNumber(word);
}

SchemeObject* Deserialization::readPair() {
    SchemeObject* first = this->readBasicObject();
    SchemeObject* second = this->readBasicObject();
    return new SchemePair(first, second);
}

SchemeObject* Deserialization::readBasicObject() {
    unsigned char byte = m_stream->readByte();
    serializableType_t type = (serializableType_t)byte;
    switch (type) {
        case TypeNull:
            return this->readNull();
        case TypeBoolean:
            return this->readBoolean();
        case TypeSymbol:
            return this->readSymbol();
        case TypeNumber:
            return this->readNumber();
        case TypePair:
            return this->readPair();
        case TypeCodeobject:
            return this->readCodeObject();
        case TypeSequence:
        case TypeInstr:
        case TypeString:
            char *err = new char;
            sprintf(err, "Expected a basic object type and got %c", byte);
            string text = string(err);
            throw DeserializationError(text);
    }
}

SchemeCodeObject* Deserialization::readCodeObject() {
    SchemeCodeObject* object = new SchemeCodeObject();
    object->name = this->readString();

    unsigned int length;

    // Read arguments
    nextByteMatchType(TypeSequence);
    length = m_stream->readWord();
    while(length-- > 0) {
        object->args.push_back(this->readString());
    }

    // Read constants
    nextByteMatchType(TypeSequence);
    length = m_stream->readWord();
    while(length-- > 0) {
        object->constants.push_back(this->readBasicObject());
    }

    // Read variable names
    nextByteMatchType(TypeSequence);
    length = m_stream->readWord();
    while(length-- > 0) {
        object->variableNames.push_back(this->readString());
    }

    // Read instructions
    nextByteMatchType(TypeSequence);
    length = m_stream->readWord();
    while(length-- > 0) {
        object->instructions.push_back(this->readInstruction());
    }

    return object;
}

