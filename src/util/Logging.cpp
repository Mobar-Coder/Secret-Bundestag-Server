/**
 * @file Logging.cpp
 * @author paul
 * @date 01.05.19
 * @brief Definition of the Logging class
 */

#include <iomanip>
#include <chrono>
#include "Logging.hpp"

namespace util {
    Logging::Logging(std::ostream &ostream, Level loggingLevel) : ostream{ostream},
                                                                         loggingLevel{loggingLevel} {}

    Logging::Logging(const Logging &log, const std::string& prefix) : ostream{log.ostream}, loggingLevel{log.loggingLevel},
                                                                      prefixes{log.prefixes} {
        prefixes.emplace_back(prefix);
    }

    void Logging::error(const std::string &msg) {
        this->logImpl(msg, Level::ERROR, "\33[91m");
    }

    void Logging::warn(const std::string &msg) {
        this->logImpl(msg, Level::WARN, "\33[33m");
    }

    void Logging::info(const std::string &msg) {
        this->logImpl(msg, Level::INFO, "\33[34m");
    }

    void Logging::debug(const std::string &msg) {
        this->logImpl(msg, Level::DEBUG, "\33[37m");
    }

    void Logging::shitTalk(const std::string &msg) {
        this->logImpl(msg, Level::ERROR, "\33[38;5;13m");
    }

    void Logging::logImpl(const std::string &string, Level level, const std::string &colorFormat) {
        if (static_cast<int>(level) >= static_cast<int>(this->loggingLevel)) {
            auto globTime = std::time(nullptr);
            auto time = *std::localtime(&globTime);
            auto timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(
                    std::chrono::system_clock::now().time_since_epoch());

            constexpr auto MILLISECONDS_PER_SECOND = 1000;

            this->ostream << "" << std::put_time(&time,"%F %T:")
                          << std::setfill('0') <<std::setw(3) << (timestamp.count() % MILLISECONDS_PER_SECOND)
                          << "\t";

            for (const auto &prefix : this->prefixes) {
                this->ostream << "[" << prefix << "]\t";
            }

            this->ostream << colorFormat << string << "\33[0m" << std::endl;
        }
    }
}
