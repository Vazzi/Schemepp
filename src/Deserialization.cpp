#include "Deserialization.hpp"
#include "BytecodeStream.hpp"
#include "Bytecode.hpp"
#include "DeserializationError.hpp"
#include <cstdio>

const unsigned INIT_WORD = 0x00010B0B;

Deserialization::Deserialization() {
    // empty
}

Deserialization::~Deserialization() {
    delete m_stream;
}

// Deserialize file with byte code
void Deserialization::deserializeByteCode(const string& fileName) {

    m_stream = new BytecodeStream(fileName.c_str());

    unsigned int initWord = m_stream->readWord();
    if (initWord != INIT_WORD) {
        throw DeserializationError("Invalid bytecode. First word is not correct.");
    }

    nextByteMatchType(Codeobject);
    // TODO: Implement
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
    nextByteMatchType(Instr);
    unsigned int wordData = m_stream->readWord();
    // Instruction bits first two from left
    // Argument the rest of the word last 6 bits
    Instruction inst = Instruction(wordData >> 24, wordData & 0xFFFFFF);
    return inst;
}

//Object* Deserialization::readNull() {

//}

//Object* Deserialization::readBoolean() {

//}

//Object* Deserialization::readSymbol() {

//}

//Object* Deserialization::readNumber() {

//}

//Object* Deserialization::readPair() {

//}

//Object* Deserialization::readSequence() {

//}
