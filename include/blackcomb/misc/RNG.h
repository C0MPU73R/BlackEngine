#ifndef BLACKCOMB_RNG_H
#define BLACKCOMB_RNG_H

#include <random>

/**
 * A wrapper for C++'s random number generator featuring a very original interface.
 */
namespace misc {
    class RNG {
    public:
        RNG();
        RNG(unsigned long seed);
        template <typename T> T randRange(T min, T max);
        template <typename T> T random();
        template <typename T> T randInt(T min, T max);
        template <typename T> T choice(std::vector<T> vec);
    private:
        std::random_device rd;
        std::mt19937 generator;
    };
}

#endif //BLACKCOMB_RNG_H
