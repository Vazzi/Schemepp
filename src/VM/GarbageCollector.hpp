#ifndef __GARBAGE_COLLECTOR_HPP__
#define __GARBAGE_COLLECTOR_HPP__

class SchemeObject;

class GarbageCollector {
    public:
        static GarbageCollector* Instance() {
            if (s_instance == 0) {
                s_instance = new GarbageCollector();
            }
            return s_instance;
        }

        void runClean();
        void registerObject(SchemeObject* object);

    private:
        static GarbageCollector* s_instance;

        GarbageCollector();
        ~GarbageCollector();

};

#endif /* ifndef __GARBAGE_COLLECTOR_HPP__ */
