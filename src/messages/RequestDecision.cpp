//
// Created by tarik on 04.01.21.
//


#include "RequestDecision.hpp"

namespace messages {
    CLASS(RequestDecision)

    RequestDecision::RequestDecision() {
        PROPERTY(type)
        PROPERTY(choices)
    }
}

