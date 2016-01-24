# Schemepp
An implementation of Scheme in C++.

Schemepp is a bytecode interpreter and Virtual machine for Scheme language. 

I used a [Bob Scheme](https://github.com/eliben/bobscheme) compiler to create bytecode files. Schemepp can read only .bobc files.

## File structure

* bin ... binnary of Schemepp (created by cmake)
* scheme
* / problem.scm ... an example in Scheme
* / problem.bob ... compiled file of the example
* / input.dat ... input data for example program in Scheme
* src ... source code of Schemepp
* CMakeLists.txt ... specification for cmake
* Readme.md ... readme

## How to compile Schemepp

1. cmake .
2. make

Executable file: bin/Schemepp

## How to run bytecode in VM

```sh
$ ./Schemepp <bytecode.bobc> <input_file> -i <output_file>
```

* `bytecode.bobc`   bytecode of scheme program
* `input_file`  is optional and is used for Scheme program to read from
* `output_file`  is optional and is used for output. If not specified than the console output is used.


