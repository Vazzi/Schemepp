#include "Pair.hpp"
#include "Null.hpp"
#include <typeinfo>

Pair::Pair(BasicObject *first, BasicObject *second) {
    this->m_first=first;
    this->m_second=second;
}

Pair::~Pair() {
    // empty
}

BasicObject* Pair::getFirst() {
    return this->m_first;
}

BasicObject* Pair::getSecond() {
    return this->m_second;
}

void Pair::setFirst(BasicObject *f) {
    this->m_first=f;
}

void Pair::setSecond(BasicObject *s) {
    this->m_second=s;
}

string Pair::print() const {
    string firstPart = m_first->print();

    const Pair* p = this;

    while (const Pair* pairSecond = dynamic_cast<const Pair*>(p->m_second)) {
        firstPart += " " + pairSecond->m_first->print();
        p = pairSecond;
    }
    //chci primo typ objektu na kterej ukazuje pointer- proto ta *
    if (typeid(*p->m_second) != typeid(Null)) {
        firstPart += " . " + p->m_second->print();
    }
    string printedLine = "(" + firstPart + ")";
    return printedLine;
}

bool equalPairs(const BasicObject* first, const BasicObject* second) {
    if (first == second) {
        return true;
    } else if (typeid(*first) != typeid(*second)) {
        return false;
    }
    return first->equalsTo(*second);
}

bool Pair::equalsTo(const BasicObject& basicObject) const{
    if (typeid(*this).name() != typeid(basicObject).name()) {
        return false;
    }
    const Pair& objectPair = dynamic_cast<const Pair&>(basicObject);
    if (equalPairs(m_first,objectPair.m_first) && (equalPairs(m_second,objectPair.m_second))) {
        return true;
    }
    return false;
}
