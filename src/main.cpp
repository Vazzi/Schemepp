#include <iostream>
#include <cstdio>

#include "Object.hpp"
#include "ConcreateObjects.hpp"
using std::string;
using std::cerr;
using namespace std;


int main(int argc, char *argv[]) {
    string fileName;
/*
    if (argc > 1) {
        fileName = argv[1];
    } else {
        cerr << "Expecting bytcode file as argument\n";
        return 1;
    }
*/
    try {
        fileName="./funkce.bobc";
        FILE* stream = fopen(fileName.c_str(), "rb");
        int  a =fgetc(stream);
        unsigned u=  a;
        u|= fgetc(stream)<<8;
        u|= fgetc(stream)<<16;
        u|= fgetc(stream)<<24;
        /*
        unsigned word = read_byte();
        word |= read_byte() << 8;
        word |= read_byte() << 16;
        word |= read_byte() << 24;
        */
        cout << u;
        Object *o=new Object();
        Null *n=new Null();
        Null *n2=new Null();
        Number *num=new Number(58);
        Number *num2=new Number(8555);
        cout << endl;
        cout << num->equalsTo(*num2);
        cout << num->print();
        Symbol *s1=new Symbol("ahoj");
        Symbol *s2=new Symbol("cau");
        Symbol *s3=new Symbol("ahoj");
        Symbol *s4=new Symbol("cau");
        cout << endl;
        cout << s1->getValue();
        cout << s2->getValue()<<endl;
        cout << s1->equalsTo(*s2)<<endl;
        cout << n->print() <<endl;
        cout << n->equalsTo(*n2)<< endl; 
        Pair *p1 = new Pair(s1,s2);
        Pair *p2 = new Pair(s3,s4);
        cout << p2->getFirst()<<endl;
        p2->setFirst(num2);
        cout << p2->equalsTo(*p1)<<endl;
        //cout << "prvni objekt: " << p1->equalsTo(*p2)<<endl;
                // TODO: Deserialize bytecode
    } catch (...) {
        cerr << "Deserialization error: " << "\n";
        return 1;
    }

    try {
        // TODO: Run code
    } catch (...) {
        cerr << "Virtual Machine error: " << "\n";
        return 1;
    }

    return 0;
}