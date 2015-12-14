#include "GarbageCollector.hpp"

#include "../Objects/SchemeObject.hpp"

using std::make_pair;

GarbageCollector* GarbageCollector::s_instance = 0;

GarbageCollector::GarbageCollector() :m_totalAllocSize(0) {
    // empty
}

GarbageCollector::~GarbageCollector() {
    // empty
}

void* GarbageCollector::allocateObject(size_t size) {
    void* memory = ::operator new(size);
    InMemObject object = make_pair(static_cast<SchemeObject*>(memory), size);
    m_objects.push_back(object);
    m_totalAllocSize += size;
    return memory;
}

void GarbageCollector::releaseObject(void* pointer) {
    ::operator delete(pointer);
}

void GarbageCollector::runClean(size_t size) {
    if (m_totalAllocSize < size) {
        return;
    }
    // TODO: Implement
}

