/**
 * @file Player.hpp
 * @author bjoern
 * @date 01.12.20
 * Definition of class Player
 */

#ifndef SECRETBUNDESTAGSERVER_PLAYER_HPP
#define SECRETBUNDESTAGSERVER_PLAYER_HPP

#include <string>
#include <optional>

#include "../enum/Role.hpp"
#include "../enum/Fraction.hpp"

/**
 * The namespace for the game model.
 * @namespace GameModel
 */
namespace GameModel {

    /**
     * This class represents a player object which can be send to a game client.
     * @class PlayerRepresentation
     */
    class PlayerRepresentation {
        public:
            std::string name;
            bool alive;
            std::optional<std::string> govRole;

            explicit PlayerRepresentation(std::string name, bool alive, std::optional<std::string> govRole);
    };

    /**
     * @class Player
     */
    class Player {

        public:

            Player(std::string name, Fraction fraction, Role role, std::size_t sessId);

            [[nodiscard]] const std::string &getName() const;

            void setName(const std::string &playerName);

            [[nodiscard]] Fraction getFraction() const;

            void setFraction(Fraction playerFraction);

            [[nodiscard]] Role getRole() const;

            void setRole(Role playerRole);

            [[nodiscard]] std::size_t getSessionId() const;

            void setAlive(bool isPlayerAlive);

            bool getAlive() const;

            void setSessionId(std::size_t sessionId);

            auto  getPlayerRepresentation() -> PlayerRepresentation;

        private:
            std::string name;
            Fraction fraction;
            Role role;
            bool alive;
            std::size_t sessionID;
    };
}

#endif // SECRETBUNDESTAGSERVER_PLAYER_HPP
