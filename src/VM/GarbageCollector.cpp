#include "GarbageCollector.hpp"

#include "../Objects/SchemeObject.hpp"

GarbageCollector* GarbageCollector::s_instance = 0;

GarbageCollector::GarbageCollector() {
    // empty
}

GarbageCollector::~GarbageCollector() {
    // empty
}

void GarbageCollector::runClean() {
    // TODO: Implement
}

void GarbageCollector::registerObject(SchemeObject* object) {
    (void) object;
    // TODO: Implement
}


