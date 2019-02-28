/*
------------------------------------------------------------------------------
rand.h: definitions for a random number generator
By Bob Jenkins, 1996, Public Domain
MODIFIED:
  960327: Creation (addition of randinit, really)
  970719: use context, not global variables, for internal state
  980324: renamed seed to flag
  980605: recommend RANDSIZL=4 for noncryptography.
  010626: note this is public domain

  20.2.2008: by Juha Nieminen: Made a C++ version, moving everything that
             garbaged the global namespace inside the .cc file. The algorithm
             itself is untouched.
------------------------------------------------------------------------------
*/
#ifndef ISAAC_RAND_HH
#define ISAAC_RAND_HH

class IsaacRand
{
 public:
    IsaacRand(unsigned seed);
    IsaacRand(unsigned seed1, unsigned seed2);
    IsaacRand(const unsigned* seeds, unsigned seedsAmount); // At most 32

    void setSeed(unsigned seed);
    void setSeed(unsigned seed1, unsigned seed2);
    void setSeed(const unsigned* seeds, unsigned seedsAmount); // At most 32

    inline unsigned getNext();


    // See documentation below
    class Iterator;
    Iterator startIterator(unsigned maxValue = unsigned(-1),
                           unsigned minValue = 0);
    Iterator endIterator(unsigned amount);



//------------------------------------------------------------------------
 private:
    typedef unsigned int ub4;      /* unsigned 4-byte quantities */
    static const ub4 RANDSIZL = 5; /* I recommend 8 for crypto, 4 for simulations */
    static const ub4 RANDSIZ = (1<<RANDSIZL);

    /* context of random number generator */
    struct randctx
    {
        ub4 randcnt;
        ub4 randrsl[RANDSIZ];
        ub4 randmem[RANDSIZ];
        ub4 randa;
        ub4 randb;
        ub4 randc;
    };

    randctx data;

    static void randinit(randctx* ctx, bool flag);
    static void isaac(randctx* ctx);
};

inline unsigned IsaacRand::getNext()
{
    return !data.randcnt-- ?
        (isaac(&data), data.randcnt=RANDSIZ-1, data.randrsl[data.randcnt]) :
        data.randrsl[data.randcnt];
}



/*===========================================================================
  IsaacRand iterator
  ------------------
  The iterator class is a convenient way to, for example, fill a data
container with random numbers. For example, creating a vector of 1000
random numbers is easy:

IsaacRand rng;
std::vector<unsigned> randValues(rng.startIterator(), rng.endIterator(1000));

  The startIterator() function can optionally be specified a maximum and a
minimum value for the generated numbers.
  The endIterator() function takes as parameter the amount of random numbers
to generate.
=============================================================================*/
#include <iterator>

class IsaacRand::Iterator
{
    friend class IsaacRand;

    IsaacRand* mRng;
    unsigned mCurrentValue, mMinValue, mRange, mCounter;

    void updateCurrentValue();
    Iterator(IsaacRand* rng, unsigned counter,
             unsigned minValue, unsigned range);

 public:
    typedef unsigned value_type;
    typedef unsigned difference_type;
    typedef unsigned* pointer;
    typedef unsigned& reference;
    typedef std::input_iterator_tag iterator_category;

    Iterator(): mRng(0), mCurrentValue(0), mCounter(0) {}

    unsigned operator*() const { return mCurrentValue; }
    Iterator& operator++();
    Iterator operator++(int);
    bool operator==(const Iterator& rhs) const;
    bool operator!=(const Iterator& rhs) const;
};

#endif
