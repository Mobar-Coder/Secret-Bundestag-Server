//
// Created by timluchterhand on 12.12.20.
//

#include "Player.hpp"
#include "OptionalSerializer.hpp"
#include <utility>

namespace messages {
    Player::Player(std::string name, bool alive, std::optional<std::string> govRole) :
            name(std::move(name)), alive(alive), govRole(std::move(govRole)) {}


    void to_json(nlohmann::json &j, const Player &p) {
        j = nlohmann::json{{"name", p.name}, {"alive", p.alive}, {"govRole", p.govRole}};
    }

    void from_json(const nlohmann::json &j, Player &p) {
        j.at("name").get_to(p.name);
        j.at("alive").get_to(p.alive);
        j.at("govRole").get_to(p.govRole);
    }
}
