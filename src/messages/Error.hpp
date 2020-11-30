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
    class Error {
        private:
            std::string message;

            GENERATE_DECLARATION(Error)

    };

}

#endif //SECRETBUNDESTAGSERVER_ERROR_HPP
