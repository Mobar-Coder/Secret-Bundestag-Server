#include <iostream>

#include "util/Logging.hpp"
#include "comm/MessageHandler.hpp"

int main() {
    util::Logging log{std::cout, 4};
    comm::MessageHandler messageHandler{8080, log};

    return 0;
}
