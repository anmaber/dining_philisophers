#include "philosopher.hpp"
#include <vector>

int main()
{
    Fork forks[5];

    bool start=false;

    Philosopher p1 (1,forks[0],forks[1],start);
    Philosopher p2 (2,forks[1],forks[2],start);
    Philosopher p3 (3,forks[2],forks[3],start);
    Philosopher p4 (4,forks[3],forks[4],start);
    Philosopher p5 (5,forks[4],forks[0],start);

    start = true;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    start = false;

    return 0;
}
