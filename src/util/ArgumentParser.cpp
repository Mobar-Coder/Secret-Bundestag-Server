/**
 * @file ArgumentParser.cpp.cc
 * @author paul
 * @date 13.12.20
 * Description here TODO
 */
#include "ArgumentParser.hpp"

#include <getopt.h>
#include <cstdlib>
#include <stdexcept>
#include <iostream>

namespace util {

    ArgumentParser::ArgumentParser(int argc, char *argv[]) {
        option options[] = {
                {"help",      no_argument,       nullptr, 'h'},
                {"port",      optional_argument, nullptr, 'p'},
                {"verbosity", optional_argument, nullptr, 'v'}
        };

        int arg;
        int portI = 8080;
        int verbosityI = static_cast<int>(Logging::Level::ERROR);

        while ((arg = getopt_long(argc, argv, "hp:v:", options, nullptr)) != -1) {
            switch (arg) {
                case 'h':
                    printHelp();
                    std::exit(0);
                case 'p':
                    try {
                        portI = std::stoi(optarg);
                    } catch (std::invalid_argument &e) {
                        throw std::invalid_argument{std::string{"Port is not a valid integer: "} + e.what()};
                    }
                    break;
                case 'v':
                    try {
                        verbosityI = std::stoi(optarg);
                    } catch (std::invalid_argument &e) {
                        throw std::invalid_argument{std::string{"Verbosity is not a valid integer: "} + e.what()};
                    }
                    break;
                default:
                    std::exit(1);
            }
        }

        if (portI <= 0 || portI >= 65536) {
            throw std::invalid_argument{"Port is not a valid 16-bit number"};
        }

        if (verbosityI < 0 or verbosityI > static_cast<int>(Logging::Level::ERROR)) {
            throw std::invalid_argument{"Verbosity invalid"};
        }

        this->port = static_cast<uint16_t>(portI);
        this->verbosity = static_cast<Logging::Level>(verbosityI);
    }

    void ArgumentParser::printHelp() {
        std::cout << "Secret-Bundestag-Server\n\n"
                  << "Options:\n"
                  << "\t -h --help Show this help message\n"
                  << "\t -p --port <port> port used for WebSockets\n"
                  << "\t -v --verbosity <int> verbosity" << std::endl;
    }

    auto ArgumentParser::getPort() const -> uint16_t {
        return this->port;
    }

    auto ArgumentParser::getVerbosity() const -> Logging::Level {
        return this->verbosity;
    }
}
