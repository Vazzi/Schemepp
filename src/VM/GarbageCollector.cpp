#include "GarbageCollector.hpp"

#include "../Objects/SchemeObject.hpp"

GarbageCollector* GarbageCollector::s_instance = 0;

GarbageCollector::GarbageCollector() :m_totalAllocSize(0) {
    // empty
}

GarbageCollector::~GarbageCollector() {
    // empty
}

void* GarbageCollector::allocateObject(size_t size) {
    (void)size;
    // TODO: Implement
    return NULL;
}

void GarbageCollector::releaseObject(void* pointer) {
    (void)pointer;
    // TODO: Implement
}

void GarbageCollector::runClean() {
    // TODO: Implement
}

void GarbageCollector::registerObject(SchemeObject* object) {
    (void) object;
    // TODO: Implement
}


