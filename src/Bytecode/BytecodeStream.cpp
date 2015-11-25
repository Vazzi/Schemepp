#include "BytecodeStream.hpp"
#include "DeserializationError.hpp"

BytecodeStream::BytecodeStream(const char* fileName) {
    m_stream = fopen(fileName, "rb");
    if (!m_stream) {
        throw DeserializationError("Unable to open bytecode file");
    }
}

BytecodeStream::~BytecodeStream() {
    fclose(m_stream);
}

// Read only one byte
unsigned int BytecodeStream::readByte() {
    int byte = fgetc(m_stream);
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

// Read string of length
string BytecodeStream::readString(unsigned int length) {
    char* buffer = new char[length + 1];
    unsigned int size = fread(buffer, 1, length, m_stream);
    if (size != length) {
        throw DeserializationError("Reading string error");
    }
    buffer[size] = '\0';
    return buffer;
}
