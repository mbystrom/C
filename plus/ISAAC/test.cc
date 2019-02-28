#include "IsaacRand.hh"
#include <cstdio>
#include <ctime>
#include <vector>

int main()
{
    IsaacRand rng(0);

    for(int i = 0; i < 128; ++i)
    {
        std::printf("%08x ", rng.getNext());
        if(i%8 == 7) std::printf("\n");
    }

    std::vector<unsigned> values(rng.startIterator(100), rng.endIterator(300));
    for(size_t i = 0; i < values.size(); ++i)
    {
        printf("%u ", values[i]);
        if(i%24 == 23) std::printf("\n");
    }

    std::printf("\nTiming...\n");
    std::clock_t t = std::clock();
    const int loops = 1000000000;
    for(int i = 0; i < loops; ++i)
        rng.getNext();

    const double seconds = double(std::clock() - t) / double(CLOCKS_PER_SEC);

    std::printf("%i values generated per second\n", int(loops/seconds));
}
