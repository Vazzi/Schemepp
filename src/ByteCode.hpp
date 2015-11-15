#ifndef __BYTECODE_HPP__
#define __BYTECODE_HPP__

// Instruction codes
const unsigned int OP_CONST = 0x00;
const unsigned int OP_LOADVAR = 0x10;
const unsigned int OP_STOREVAR = 0x11;
const unsigned int OP_DEFVAR = 0x12;
const unsigned int OP_FUNCTION = 0x20;
const unsigned int OP_POP = 0x30;
const unsigned int OP_JUMP = 0x40;
const unsigned int OP_FJUMP = 0x41;
const unsigned int OP_RETURN = 0x50;
const unsigned int OP_CALL = 0x51;
const unsigned int OP_INVALID = 0xFF;


// Instruction with argument
struct Instruction {
    Instruction(unsigned opCode = OP_INVALID, unsigned arg = 0)
        : opCode(opCode), arg(arg) {}
    unsigned int opCode;
    unsigned int arg;
}

#endif
