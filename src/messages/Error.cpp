/**
 * @file Error.cpp
 * @author paul
 * @date 30.11.20
 * Description here TODO
 */
#include "Error.hpp"

namespace messages {
    Error::Error(const std::string& message) : message{message} {
        PROPERTY(message)
    }

    auto Error::getMessageName() const -> std::string {
        return "Error";
    }

}
