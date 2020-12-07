#include <iostream>
#include <chrono>

#include "util/Logging.hpp"
#include "comm/LobbyHandler.hpp"

auto main() -> int {
    util::Logging log{std::cout, 4};
    comm::LobbyHandler lobbyHandler{8080, log};

    while (true) {
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(1h);
    }
}
