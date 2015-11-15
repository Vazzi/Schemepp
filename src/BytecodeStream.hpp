#ifndef __BYTECODE_STREAM_HPP__
#define __BYTECODE_STREAM_HPP__

#include <cstdio>

using std::FILE;

class BytecodeStream {
    public:
        BytecodeStream(const char* fileName);
        ~BytecodeStream();

    private:
        FILE* stream;
};

#endif
