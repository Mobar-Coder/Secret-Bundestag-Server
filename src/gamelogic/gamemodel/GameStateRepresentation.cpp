/**
 * @file GameStateRepresentation.cpp
 * @author bjoern
 * @date 08.12.20
 * Description here TODO
 */

#include "GameStateRepresentation.hpp"

#include <utility>

namespace GameModel {

    GameStateRepresentation::GameStateRepresentation(int liberalPolicies, int fascistPolicies,
                                                     std::optional<std::string> chancellor, int electionTracker,
                                                     std::vector<GameModel::Player> players, int cardPile,
                                                     int discardPile) :
                                                     liberalPolicies(liberalPolicies), fascistPolicies(fascistPolicies),
                                                     chancellor(std::move(chancellor)),
                                                     electionTracker(electionTracker), players(std::move(players)),
                                                     cardPile(cardPile), discardPile(discardPile){
    }

}
