#include <iostream>

#include "util/Logging.hpp"
#include "comm/ConnectionHandler.hpp"

int main() {
    util::Logging log{std::cout, 4};
    comm::ConnectionHandler messageHandler{8080, log};

    return 0;
}
