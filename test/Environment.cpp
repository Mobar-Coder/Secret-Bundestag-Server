//
// Created by bjorn on 09.12.20.
//

#include <gtest/gtest.h>

#include "gamelogic/gamemodel/Environment.hpp"

TEST(einvironment_test, draw_n_cards) {
    GameModel::Player player("Björn", GameModel::Fraction::LiberalParty, GameModel::Role::NoneRole, 0);
    std::vector<GameModel::Player> players;
    players.emplace_back(player);
    GameModel::Environment environment(players);
    EXPECT_ANY_THROW(environment.drawNCards(18));
    EXPECT_NO_THROW(environment.drawNCards(3));
}