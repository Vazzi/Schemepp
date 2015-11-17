#include "Deserialization.hpp"
#include "BytecodeStream.hpp"
#include "DeserializationError.hpp"
#include <cstdio>

const unsigned INIT_WORD = 0x00010B0B;

// Deserialize file with byte code
void Deserialization::deserializeByteCode(const string& fileName) {

    BytecodeStream stream = BytecodeStream(fileName.c_str());

    unsigned int initWord = stream.readWord();
    if (initWord != INIT_WORD) {
        throw DeserializationError("Invalid bytecode. First word is not correct.");
    }

    nextByteMatchType(stream, Codeobject);
    // TODO: Implement
}

// Throw exception if next byte in stream does not match type
void Deserialization::nextByteMatchType(BytecodeStream& stream,
        const serializableType_t& type) {

    unsigned char byte = stream.readByte();
    if (byte != type) {
        char *err = new char;
        sprintf(err, "Expected type %c and got %c", type, byte);
        string text = string(err);
        throw DeserializationError(text);
    }
}
