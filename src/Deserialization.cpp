#include "Deserialization.hpp"
#include "BytecodeStream.hpp"

// Deserialize file with byte code
void Deserialization::deserializeByteCode(const string& fileName) {

    BytecodeStream* stream = new BytecodeStream(fileName.c_str());
    // TODO: Implement
}
