//
// Created by bjorn on 07.12.20.
//

#include <gtest/gtest.h>
#include "src/gamelogic/gamemodel/CardRange.hpp"

TEST(card_range_test, select_policy) {
    GameModel::Board board{};
    board.getCardPile()->emplace_back(GameModel::CardType::Fascist);
    board.getCardPile()->emplace_back(GameModel::CardType::Fascist);
    board.getCardPile()->emplace_back(GameModel::CardType::Liberal);
    board.getCardPile()->emplace_back(GameModel::CardType::Liberal);

    GameModel::CardRange cardRange{std::make_shared<GameModel::Board>(board), 1};
    EXPECT_FALSE(cardRange.selectForPolicy(GameModel::CardType::Fascist));
    EXPECT_TRUE(cardRange.selectForPolicy(GameModel::CardType::Liberal));
}