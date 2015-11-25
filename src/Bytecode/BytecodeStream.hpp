#ifndef __BYTECODE_STREAM_HPP__
#define __BYTECODE_STREAM_HPP__

#include <cstdio>
#include <string>

using std::FILE;
using std::string;

class BytecodeStream {
    public:
        BytecodeStream(const char* fileName);
        ~BytecodeStream();

        unsigned int readByte();
        unsigned int readWord();
        string readString(unsigned int length);

    private:
        FILE* m_stream;
};

#endif
