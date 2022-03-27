#ifndef blackengine_RNG_H
#define blackengine_RNG_H

#include <random>

namespace blackengine::misc {
    /**
     * A wrapper for C++'s random number generator featuring a very original interface.
     */
    class RNG {
    public:
        RNG();
        RNG(unsigned long seed);
        template <typename T> T randRange(T min, T max);
        template <typename T> T random();
        template <typename T> T randInt(T min, T max);
        template <typename T> T choice(std::vector<T> vec);
        void setSeed(unsigned long seed);
    private:
        std::random_device rd;
        std::mt19937 generator;
    };
}

#endif //blackengine_RNG_H
