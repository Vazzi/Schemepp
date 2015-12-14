#ifndef __GARBAGE_COLLECTOR_HPP__
#define __GARBAGE_COLLECTOR_HPP__

#include <utility>
#include <list>

class SchemeObject;

using std::pair;
using std::list;
using std::size_t;

typedef pair<SchemeObject*, size_t> InMemObject;

class GarbageCollector {
    public:
        static GarbageCollector* Instance() {
            if (s_instance == 0) {
                s_instance = new GarbageCollector();
            }
            return s_instance;
        }

        void* allocateObject(size_t size);
        void releaseObject(void* pointer);
        void runClean(size_t size);

    private:
        static GarbageCollector* s_instance;

        GarbageCollector();
        ~GarbageCollector();

        list<InMemObject> m_objects;
        size_t m_totalAllocSize;
};

#endif /* ifndef __GARBAGE_COLLECTOR_HPP__ */
