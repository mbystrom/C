#include <iostream>
#include <ctime>

int fib (int num)
{
    if (num <= 1) return num;
    else return fib(num-1) + fib(num-2);
}

int main()
{
    std::clock_t start = std::clock();
    int fib40 = fib(40);
    std::cout << fib40 << std::endl;
    float finaltime = ((float)std::clock() - (float)start);
    std::cout << "Took " << finaltime/1000 << " ms";
}
