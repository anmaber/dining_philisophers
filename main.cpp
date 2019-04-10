#include "philosopher.hpp"

int main()
{
    Fork f1,f2;
    Philosopher p(1,f1,f2);
    return 0;
}
