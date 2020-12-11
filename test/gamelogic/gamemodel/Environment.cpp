//
// Created by bjorn on 09.12.20.
//

#include <gtest/gtest.h>

#include "gamelogic/gamemodel/Environment.hpp"

TEST(GameModel_Environment, draw_n_cards) {
    GameModel::Player player("Björn", GameModel::Fraction::LIBERAL_PARTY, GameModel::Role::NONE_ROLE, 0);
    std::vector<GameModel::Player> players;
    players.emplace_back(player);
    GameModel::Environment environment(players);
    EXPECT_ANY_THROW(environment.drawNCards(18));
    EXPECT_NO_THROW(environment.drawNCards(3));
}