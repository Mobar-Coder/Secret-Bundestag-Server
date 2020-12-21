//
// Created by timluchterhand on 12.12.20.
//

#ifndef SECRETBUNDESTAGSERVER_PLAYER_HPP
#define SECRETBUNDESTAGSERVER_PLAYER_HPP

#include <string>
#include <nlohmann/json.hpp>

namespace messages {
    struct Player {
        Player(std::string name, bool alive, std::optional<std::string> govRole);
        Player() = default;

        std::string name{};
        bool alive{};
        std::optional<std::string> govRole{};
    };

    void to_json(nlohmann::json& j, const Player& p);

    void from_json(const nlohmann::json& j, Player& p);
}


#endif //SECRETBUNDESTAGSERVER_PLAYER_HPP
