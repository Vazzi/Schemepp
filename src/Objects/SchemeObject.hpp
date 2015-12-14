#ifndef __SCHEME_OBJECT_HPP__
#define __SCHEME_OBJECT_HPP__

#include <string>

using std::string;

class SchemeObject {
    public:
        SchemeObject();
        virtual ~SchemeObject();
        virtual bool equalsTo(const SchemeObject& object) const;
        virtual string print() const;

        void* operator new(size_t size);
        void operator delete(void* p);

        // Garbage collector marking
        virtual void gc_mark();
        virtual void gc_unMark();
        virtual bool gc_isMarked() const;
        virtual void gc_markPointed() {}; // Only for inheriting objects that has some pointers to other objects

    protected:
        bool m_gc_isMarked;
};

#endif

