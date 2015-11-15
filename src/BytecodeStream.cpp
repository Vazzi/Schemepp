#include "BytecodeStream.hpp"

BytecodeStream::BytecodeStream(const char* fileName) {
    stream = fopen(fileName, "rb");
    if (!stream) {
        // TODO: Throw some error
        // "Unable to open bytecode file"
    }
}

BytecodeStream::~BytecodeStream() {
    fclose(stream);
}
