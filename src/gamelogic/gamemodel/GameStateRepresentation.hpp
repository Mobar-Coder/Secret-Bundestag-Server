/**
 * @file GameStateRepresentation.hpp
 * @author bjoern
 * @date 08.12.20
 * This class represents a snapshot of the current game state which can be send to a game client.
 */

#ifndef SECRETBUNDESTAGSERVER_GAMESTATEREPRESENTATION_HPP
#define SECRETBUNDESTAGSERVER_GAMESTATEREPRESENTATION_HPP

#include <optional>
#include <vector>
#include "Player.hpp"

/**
 * The namespace for the game model.
 * @namespace GameModel
 */
namespace GameModel {

    /**
     * This class represents a snapshot of the current game state which can be send to a game client.
     * @class GameStateRepresentation
     */
    class GameStateRepresentation {

        public:

            int liberalPolicies;
            int fascistPolicies;
            std::optional<std::string> chancellor;
            int electionTracker;
            std::vector<GameModel::Player> players;
            int cardPile;
            int discardPile;

            GameStateRepresentation(int liberalPolicies, int fascistPolicies, std::optional<std::string> chancellor,
                                    int electionTracker, std::vector<GameModel::Player> players, int cardPile,
                                    int discardPile);

    };
}

#endif //SECRETBUNDESTAGSERVER_GAMESTATEREPRESENTATION_HPP
