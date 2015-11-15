#ifndef __BYTECODE_HPP__
#define __BYTECODE_HPP__

// Instruction codes
const unsigned OP_CONST = 0x00;
const unsigned OP_LOADVAR = 0x10;
const unsigned OP_STOREVAR = 0x11;
const unsigned OP_DEFVAR = 0x12;
const unsigned OP_FUNCTION = 0x20;
const unsigned OP_POP = 0x30;
const unsigned OP_JUMP = 0x40;
const unsigned OP_FJUMP = 0x41;
const unsigned OP_RETURN = 0x50;
const unsigned OP_CALL = 0x51;
const unsigned OP_INVALID = 0xFF;

#endif
