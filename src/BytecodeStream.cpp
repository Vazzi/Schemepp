#include "BytecodeStream.hpp"
#include "DeserializationError.hpp"

BytecodeStream::BytecodeStream(const char* fileName) {
    stream = fopen(fileName, "rb");
    if (!stream) {
        throw DeserializationError("Unable to open bytecode file");
    }
}

BytecodeStream::~BytecodeStream() {
    fclose(stream);
}

// Read only one byte
unsigned int BytecodeStream::readByte() {
    int byte = fgetc(stream);
    if (byte == EOF) {
        throw DeserializationError("Bytecode is not complete");
    }
    return byte & 0xFF;
}

// Read the whole word in little endian
unsigned int BytecodeStream::readWord() {
    unsigned int word = readByte();
    word |= readByte() << 8;
    word |= readByte() << 16;
    word |= readByte() << 24;
    return word;
}
