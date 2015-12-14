#include "GarbageCollector.hpp"

#include "../Objects/SchemeObject.hpp"
#include "VirtualMachine.hpp"

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

void GarbageCollector::runClean(size_t sizeLimit) {
    if (m_totalAllocSize < sizeLimit) {
        return;
    }

    m_vm->GCMarkRoots();

    list<InMemObject>::iterator it = m_objects.begin();
    while (it != m_objects.end()) {
        SchemeObject* object = it->first;
        size_t objSize = it->second;
        if (object->isGCMarked()) {
            object->GCUnMark();
            it++;
        } else {
            it = m_objects.erase(it);
            delete object;
            m_totalAllocSize -= objSize;
        }
    }
}

void GarbageCollector::registerVM(VirtualMachine* vm) {
    m_vm = vm;
}
