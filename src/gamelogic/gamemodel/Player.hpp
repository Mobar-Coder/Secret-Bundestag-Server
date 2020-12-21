/**
 * @file Player.hpp
 * @author bjoern
 * @date 01.12.20
 * Definition of class Player
 */

#ifndef SECRETBUNDESTAGSERVER_PLAYER_HPP
#define SECRETBUNDESTAGSERVER_PLAYER_HPP

#include <string>

#include "../enum/Role.hpp"
#include "../enum/Fraction.hpp"

namespace GameModel {
    class Player {

        private:
            std::string name;
            Fraction fraction;
            Role role;
            std::size_t sessionID;
            bool alive = true;

        public:

            Player(std::string name, Fraction fraction, Role role, std::size_t sessId);

            [[nodiscard]] auto getName() const -> const std::string &;

            void setName(const std::string &playerName);

            [[nodiscard]] auto getFraction() const -> Fraction;

            void setFraction(Fraction playerFraction);

            [[nodiscard]] auto getRole() const -> Role;

            void setRole(Role playerRole);

            [[nodiscard]] auto getSessionId() const -> std::size_t;

            void setSessionId(std::size_t sessionId);

            [[nodiscard]] auto isAlive() const -> bool;

            void setAlive(bool isAlive);
    };

}

#endif // SECRETBUNDESTAGSERVER_PLAYER_HPP
