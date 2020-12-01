/**
 * @file Error.cpp
 * @author paul
 * @date 30.11.20
 * Description here TODO
 */
#include "Error.hpp"

#include <utility>

namespace messages {
    Error::Error(std::string  message) : message{std::move(message)} {
        PROPERTY(message)
    }

    auto Error::getMessageName() const -> std::string {
        return "Error";
    }

}
