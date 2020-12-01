/**
 * @file Error.cpp
 * @author paul
 * @date 30.11.20
 * Description here TODO
 */
#include "Error.hpp"

#include <utility>

namespace messages {
    Error::Error() {
        PROPERTY(message)
    }

    auto Error::getMessageName() const -> std::string {
        return "Error";
    }

}
