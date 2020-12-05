/**
 * @file JoinRequest.cpp
 * @author paul
 * @date 01.12.20
 * Description here TODO
 */
#include "JoinRequest.hpp"

namespace messages {
    CLASS(JoinRequest)

    JoinRequest::JoinRequest() {
        PROPERTY(lobbyName)
    }
}
