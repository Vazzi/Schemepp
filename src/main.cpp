#include <iostream>
#include <cstdio>

#include "BasicObject.hpp"
#include "Bool.hpp"
#include "Null.hpp"
#include "Number.hpp"
#include "Pair.hpp"
#include "Symbol.hpp"



using std::string;
using std::cerr;
using namespace std;
void posli(int &cislo){
    cout << "cislo: "<< &cislo << endl;
    cislo+=55;
}
void poslipointer(int* neco){
    cout << "cislo: "<< &neco << endl;
    *neco+=55;
}
void pokus(){
    int *p;
    int i2= 99;
    p=&i2;
    int i=67;
    posli(i);
    cout << i <<endl;
    cout << p <<endl;
    poslipointer(p);
    cout << p <<endl;
    cout << *p <<endl;
    cout << "--------"<<endl;
    cout << p<<endl;
    cout << &(*p)<<endl;

}
int main(int argc, char *argv[]) {
    string fileName;
    cout << "co to je< "<<endl;
/*
    if (argc > 1) {
        fileName = argv[1];
    } else {
        cerr << "Expecting bytcode file as argument\n";
        return 1;
    }
*/
    try {
        /*
        fileName="./funkce.bobc";
        FILE* stream = fopen(fileName.c_str(), "rb");
        int  a =fgetc(stream);
        unsigned u=  a;
        u|= fgetc(stream)<<8;
        u|= fgetc(stream)<<16;
        u|= fgetc(stream)<<24;
        
        unsigned word = read_byte();
        word |= read_byte() << 8;
        word |= read_byte() << 16;
        word |= read_byte() << 24;
        
        cout << u;
         * */
        BasicObject *o=new BasicObject();
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
        Symbol *s4=new Symbol("cau55");
        cout << endl;
        cout << s1->print();
        cout << s2->print()<<endl;
        cout << s1->equalsTo(*s2)<<endl;
        cout << n->print() <<endl;
        cout << n->equalsTo(*n2)<< endl; 
        cout << "---------------------"<<endl;
        cout << s2->equalsTo(*s4)<<endl;
        //pokus();
        
        
        Pair *p1 = new Pair(s1,s2);
        Pair *p2 = new Pair(s3,s4);
        Pair *p3 = new Pair(s3,p1);
        Pair *p4 = new Pair(num,num2);
        Pair *p5 = new Pair(p2,p3);
        cout << p2->getFirst()<<endl;
        cout << p1->print()<<endl;
        cout << p3->print()<<endl;
        
        cout << p5->print()<<endl;
        
        
        
       
        cout << "shoda?: " << p2->equalsTo(*p1) << endl;
         
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