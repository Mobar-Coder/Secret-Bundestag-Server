#include <iostream>
#include <chrono>

#include "util/Logging.hpp"
#include "comm/LobbyHandler.hpp"
#include "util/ArgumentParser.hpp"

auto main(int argc, char *argv[]) -> int {
    util::ArgumentParser argumentParser{argc, argv};

    util::Logging log{std::cout, argumentParser.getVerbosity()};
    comm::LobbyHandler lobbyHandler{argumentParser.getPort(), log};

    while (true) {
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(1h);
    }
}
