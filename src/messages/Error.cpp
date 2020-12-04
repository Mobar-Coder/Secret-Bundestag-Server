/**
 * @file Error.cpp
 * @author paul
 * @date 30.11.20
 * Description here TODO
 */
#include "Error.hpp"

namespace messages {
    Error::Error() {
        CLASS(Error)
        PROPERTY(message)
    }
}
