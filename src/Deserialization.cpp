#include "Deserialization.hpp"
#include "BytecodeStream.hpp"

const unsigned INIT_WORD = 0x00010B0B;

// Deserialize file with byte code
void Deserialization::deserializeByteCode(const string& fileName) {

    BytecodeStream* stream = new BytecodeStream(fileName.c_str());

    unsigned int initWord = stream->readWord();
    if (initWord != INIT_WORD) {
        throw DeserializationError("Invalid bytecode. First word is not correct.");
    }
    // TODO: Implement
    delete stream;
}
