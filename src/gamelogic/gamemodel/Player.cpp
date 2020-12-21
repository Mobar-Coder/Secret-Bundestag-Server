/**
 * @file Player.cpp
 * @author bjoern
 * @date 01.12.20
 * Declaration of all Player Methods
 */

#include "Player.hpp"

#include <utility>

namespace GameModel {

    Player::Player(std::string name, const Fraction fraction, const Role role, const std::size_t sessId) : name(
            std::move(name)), fraction(fraction), role(role), sessionID(sessId) {

    }

    auto Player::getName() const -> const std::string & {
        return name;
    }

    void Player::setName(const std::string &playerName) {
        name = playerName;
    }

    auto Player::getFraction() const -> Fraction {
        return fraction;
    }

    void Player::setFraction(Fraction playerFraction) {
        fraction = playerFraction;
    }

    auto Player::getRole() const -> Role {
        return role;
    }

    void Player::setRole(Role playerRole) {
        role = playerRole;
    }

    auto Player::getSessionId() const -> size_t {
        return sessionID;
    }

    void Player::setSessionId(size_t sessionId) {
        sessionID = sessionId;
    }

    auto Player::isAlive() const -> bool {
        return alive;
    }

    void Player::setAlive(bool isAlive) {
        this->alive = isAlive;
    }
}
