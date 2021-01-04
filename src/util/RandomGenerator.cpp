//
// Created by bjorn on 04.01.21.
//

#include <random>
#include "RandomGenerator.hpp"

namespace Util {
    auto rng(int min, int max) -> int {
        static std::random_device rd;
        static std::default_random_engine el(rd());
        std::uniform_int_distribution dist(min, max);
        return dist(el);

    }

    auto rng(double min, double max) -> double {
        static std::random_device rd;
        static std::default_random_engine el(rd());
        std::uniform_real_distribution dist(min, max);
        return dist(el);
    }
}