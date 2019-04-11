#pragma once
#include <thread>
#include <mutex>
#include <string>

struct Fork{
   mutable std::mutex mutex;
};

class Philosopher{

    int philosopherID;
    Fork& leftFork;
    Fork& rightFork;
    bool& startEating;
    std::thread lifeThread;


public:

    Philosopher(int ID,Fork& left,Fork& right,bool& start);
    void eat();
    void think();
    void dine();
    ~Philosopher();
    void print(const std::string &what);
};

