#pragma once
#include <thread>
#include <mutex>
#include <chrono>

class Fork{
    std::mutex mutex;
};

class Philosopher{

    int philosopherID;
    std::thread lifeThread;
    Fork& leftFork;
    Fork& righFork;

public:

    Philosopher();
    void eat();
    void think();
    void dine();
};

