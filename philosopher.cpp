#include "philosopher.hpp"

#include <functional>
#include <iostream>
#include <chrono>

std::mutex coutMutex;


Philosopher::Philosopher(int ID, Fork& left, Fork& right, bool &start)
    : philosopherID(ID),
      leftFork(left),
      rightFork(right),
      startEating(start),
      lifeThread(&Philosopher::dine,this)
{}

void Philosopher::print(const std::string& what)
{
    std::lock_guard<std::mutex> lock(coutMutex);
    std::cout<<philosopherID<<"\t"<<what<<"\n";
}

void Philosopher::eat()
{

    std::scoped_lock lock(leftFork.mutex, rightFork.mutex);
    /*
    std::lock(leftFork.mutex, rightFork.mutex);
    std::lock_guard<std::mutex> leftLock(leftFork.mutex,   std::adopt_lock);
    std::lock_guard<std::mutex> rightLock(rightFork.mutex, std::adopt_lock);
    */

    /*
    leftFork.mutex.lock();
    rightFork.mutex.lock();
    */

    print("started eating");
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    print("stopped eating");
    /*
    rightFork.mutex.unlock();
    leftFork.mutex.unlock();
    */
}

void Philosopher::think()
{

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    print("is thinking");
}

void Philosopher::dine()
{
    while(!startEating);
    while(startEating)
    {
        eat();
        think();
    }

}

Philosopher::~Philosopher()
{
    if (lifeThread.joinable())
        lifeThread.join();
}
