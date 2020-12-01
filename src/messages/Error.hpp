/**
 * @file Error.hpp
 * @author paul
 * @date 30.11.20
 * Description here TODO
 */
#ifndef SECRETBUNDESTAGSERVER_ERROR_HPP
#define SECRETBUNDESTAGSERVER_ERROR_HPP

#include "../util/Serializable.hpp"

namespace messages {
    JSON_CLASS(Error,
   std::string message;
    )
}

#endif //SECRETBUNDESTAGSERVER_ERROR_HPP
