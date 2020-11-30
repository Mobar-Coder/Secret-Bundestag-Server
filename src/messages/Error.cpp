/**
 * @file Error.cpp
 * @author paul
 * @date 30.11.20
 * Description here TODO
 */
#include "Error.hpp"

namespace messages {
    GENERATE_TO(Error,
                TO_MEMBER(message)
    )

    GENERATE_FROM(Error,
                  FROM_MEMBER(message)
    )
}
