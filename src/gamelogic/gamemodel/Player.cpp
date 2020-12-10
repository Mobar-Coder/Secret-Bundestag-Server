/**
 * @file Player.cpp
 * @author bjoern
 * @date 01.12.20
 * Description here TODO
 */

#include "Player.hpp"

#include <utility>

namespace GameModel {

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

    size_t Player::getSessionId() const {
        return sessionID;
    }

    void Player::setSessionId(size_t sessionId) {
        sessionID = sessionId;
    }
}
