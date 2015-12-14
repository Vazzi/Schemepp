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
        virtual void GCMark();
        virtual void GCUnMark();
        virtual bool isGCMarked() const;
        virtual void GCMarkPointed() {}; // Only for inheriting objects that has some pointers to other objects

    protected:
        bool m_isGCMarked;
};

#endif

