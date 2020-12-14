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
            bool alive;

        public:

            Player(std::string name, Fraction fraction, Role role, std::size_t sessId);

            [[nodiscard]] const std::string &getName() const;

            void setName(const std::string &playerName);

            [[nodiscard]] Fraction getFraction() const;

            void setFraction(Fraction playerFraction);

            [[nodiscard]] Role getRole() const;

            void setRole(Role playerRole);

            [[nodiscard]] std::size_t getSessionId() const;

            void setSessionId(std::size_t sessionId);

            [[nodiscard]] auto isAlive() const -> bool;

            void setAlive(bool alive);
    };

}

#endif // SECRETBUNDESTAGSERVER_PLAYER_HPP
