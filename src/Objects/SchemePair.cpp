#include "SchemePair.hpp"
#include "SchemeNull.hpp"
#include <typeinfo>

SchemePair::SchemePair(SchemeObject *first, SchemeObject *second) {
    this->m_first=first;
    this->m_second=second;
}

SchemePair::~SchemePair() {
    // empty
}

SchemeObject* SchemePair::getFirst() {
    return this->m_first;
}

SchemeObject* SchemePair::getSecond() {
    return this->m_second;
}

void SchemePair::setFirst(SchemeObject *f) {
    this->m_first=f;
}

void SchemePair::setSecond(SchemeObject *s) {
    this->m_second=s;
}

string SchemePair::print() const {
    string firstPart = m_first->print();

    const SchemePair* p = this;

    while (const SchemePair* pairSecond = dynamic_cast<const SchemePair*>(p->m_second)) {
        firstPart += " " + pairSecond->m_first->print();
        p = pairSecond;
    }
    //chci primo typ objektu na kterej ukazuje pointer- proto ta *
    if (typeid(*p->m_second) != typeid(SchemeNull)) {
        firstPart += " . " + p->m_second->print();
    }
    string printedLine = "(" + firstPart + ")";
    return printedLine;
}

bool equalSchemePairs(const SchemeObject* first, const SchemeObject* second) {
    if (first == second) {
        return true;
    } else if (typeid(*first) != typeid(*second)) {
        return false;
    }
    return first->equalsTo(*second);
}

bool SchemePair::equalsTo(const SchemeObject& basicObject) const{
    if (typeid(*this).name() != typeid(basicObject).name()) {
        return false;
    }
    const SchemePair& objectSchemePair = dynamic_cast<const SchemePair&>(basicObject);
    if (equalSchemePairs(m_first,objectSchemePair.m_first) && (equalSchemePairs(m_second,objectSchemePair.m_second))) {
        return true;
    }
    return false;
}

void SchemePair::gc_markPointed() {
    m_first->gc_mark();
    m_second->gc_mark();
}
