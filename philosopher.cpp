#include "philosopher.hpp"

#include <chrono>
#include <functional>


Philosopher::Philosopher(int ID, Fork& left, Fork& right)
    : philosopherID(ID),
      leftFork(left),
      rightFork(right),
      lifeThread(&Philosopher::dine,this)
{}

void Philosopher::eat()
{

}

void Philosopher::think()
{

}

void Philosopher::dine()
{

}

Philosopher::~Philosopher()
{
    if (lifeThread.joinable())
        lifeThread.join();
}
