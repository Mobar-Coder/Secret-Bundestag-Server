/**
 * @file Player.cpp
 * @author bjoern
 * @date 01.12.20
 * Declaration of all Player Methods
 */

#include "Player.hpp"

#include <utility>

namespace GameModel {

    // PlayerRepresentation class implementation -----------------------------------------------------------------------

    PlayerRepresentation::PlayerRepresentation(std::string name, bool alive, std::optional<std::string> govRole) :
            name(std::move(name)), alive(alive), govRole(std::move(govRole)) {
    }

    // -----------------------------------------------------------------------------------------------------------------

    // Player class implementation -------------------------------------------------------------------------------------

    Player::Player(std::string name, const Fraction fraction, const Role role, const std::size_t sessId) : name(
            std::move(name)), fraction(fraction), role(role), sessionID(sessId) {

    }

    const std::string &Player::getName() const {
        return name;
    }

    void Player::setName(const std::string &playerName) {
        name = playerName;
    }

    Fraction Player::getFraction() const {
        return fraction;
    }

    void Player::setFraction(Fraction playerFraction) {
        fraction = playerFraction;
    }

    Role Player::getRole() const {
        return role;
    }

    void Player::setRole(Role playerRole) {
        role = playerRole;
    }

    void Player::setAlive(bool isPlayerAlive) {
        this->alive = isPlayerAlive;
    }

    bool Player::getAlive() const {
        return alive;
    }

    void Player::setSessionId(size_t sessionId) {
        sessionID = sessionId;
    }


    size_t Player::getSessionId() const {
        return sessionID;
    }

    // ToDo Fix return...
    auto Player::getPlayerRepresentation() -> PlayerRepresentation {
        return PlayerRepresentation(name, alive, "");
    }

    // -----------------------------------------------------------------------------------------------------------------
}
