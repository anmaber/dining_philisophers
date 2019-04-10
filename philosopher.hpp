#pragma once
#include <thread>
#include <mutex>

struct Fork{
   mutable std::mutex mutex;
};

class Philosopher{

    int philosopherID;
    Fork& leftFork;
    Fork& rightFork;
    std::thread lifeThread;


public:

    Philosopher(int ID,Fork& left,Fork& right);
    void eat();
    void think();
    void dine();
    ~Philosopher();
};

