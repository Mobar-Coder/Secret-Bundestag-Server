/**
 * @file ArgumentParser.hpp.h
 * @author paul
 * @date 13.12.20
 * Description here TODO
 */
#ifndef SECRETBUNDESTAGSERVER_ARGUMENTPARSER_HPP
#define SECRETBUNDESTAGSERVER_ARGUMENTPARSER_HPP

#include <cstdint>
#include "Logging.hpp"

namespace util {
    class ArgumentParser {
        public:
            ArgumentParser(int argc, char *argv[]);

            auto getPort() const -> uint16_t ;

            auto getVerbosity() const -> Logging::Level;

        private:
            void printHelp();

            uint16_t port;
            Logging::Level verbosity;
    };
}

#endif //SECRETBUNDESTAGSERVER_ARGUMENTPARSER_HPP
