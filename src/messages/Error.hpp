/**
 * @file Error.hpp
 * @author paul
 * @date 30.11.20
 * Description here TODO
 */
#ifndef SECRETBUNDESTAGSERVER_ERROR_HPP
#define SECRETBUNDESTAGSERVER_ERROR_HPP

#include "Message.hpp"

namespace messages {
    struct Error : public Message {
        Error();

        std::string message;

        [[nodiscard]] auto getMessageName() const -> std::string override;
    };
}

#endif //SECRETBUNDESTAGSERVER_ERROR_HPP
