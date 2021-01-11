//
// Created by bjorn on 04.01.21.
//

#ifndef SECRETBUNDESTAGSERVER_RANDOMGENERATOR_HPP
#define SECRETBUNDESTAGSERVER_RANDOMGENERATOR_HPP
namespace Util {
    auto rng(int min, int max) -> int;

    auto rng(double min, double max) -> double;
}

#endif //SECRETBUNDESTAGSERVER_RANDOMGENERATOR_HPP
