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

TEST(card_range_test, constructor0) {
    GameModel::Board board{};
    board.getCardPile()->emplace_back(GameModel::CardType::Fascist);
    board.getCardPile()->emplace_back(GameModel::CardType::Fascist);
    board.getCardPile()->emplace_back(GameModel::CardType::Liberal);
    board.getCardPile()->emplace_back(GameModel::CardType::Liberal);

    GameModel::CardRange cardRange{std::make_shared<GameModel::Board>(board), 2};
    EXPECT_EQ(board.getCardPile()->at(0), GameModel::CardType::Fascist);
    EXPECT_EQ(board.getCardPile()->at(1), GameModel::CardType::Fascist);
    EXPECT_EQ(board.getCardPile()->size(), 2);
}

TEST(card_range_test, constructor1) {
    GameModel::Board board{};
    board.getCardPile()->emplace_back(GameModel::CardType::Fascist);
    board.getCardPile()->emplace_back(GameModel::CardType::Fascist);
    board.getCardPile()->emplace_back(GameModel::CardType::Liberal);
    board.getCardPile()->emplace_back(GameModel::CardType::Liberal);

    EXPECT_ANY_THROW((GameModel::CardRange{std::make_shared<GameModel::Board>(board), 5}));
}

TEST(card_range_test, destructor) {
    GameModel::Board board{};
    board.getCardPile()->emplace_back(GameModel::CardType::Fascist);
    board.getCardPile()->emplace_back(GameModel::CardType::Fascist);
    board.getCardPile()->emplace_back(GameModel::CardType::Liberal);
    board.getCardPile()->emplace_back(GameModel::CardType::Liberal);

    {
        GameModel::CardRange cardRange{std::make_shared<GameModel::Board>(board), 2};
        EXPECT_EQ(board.getCardPile()->at(0), GameModel::CardType::Fascist);
        EXPECT_EQ(board.getCardPile()->at(1), GameModel::CardType::Fascist);
        EXPECT_EQ(board.getCardPile()->size(), 2);
    }

    EXPECT_EQ(board.getCardPile()->at(0), GameModel::CardType::Fascist);
    EXPECT_EQ(board.getCardPile()->at(1), GameModel::CardType::Fascist);
    EXPECT_EQ(board.getCardPile()->at(2), GameModel::CardType::Liberal);
    EXPECT_EQ(board.getCardPile()->at(3), GameModel::CardType::Liberal);
    EXPECT_EQ(board.getCardPile()->size(), 4);
}

TEST(card_range_test, discard_card) {
    GameModel::Board board{};
    board.getCardPile()->emplace_back(GameModel::CardType::Fascist);
    board.getCardPile()->emplace_back(GameModel::CardType::Fascist);
    board.getCardPile()->emplace_back(GameModel::CardType::Liberal);
    board.getCardPile()->emplace_back(GameModel::CardType::Liberal);

    GameModel::CardRange cardRange{std::make_shared<GameModel::Board>(board), 2};
    EXPECT_FALSE(cardRange.discard(GameModel::CardType::Fascist));
    EXPECT_TRUE(cardRange.discard(GameModel::CardType::Liberal));
}

TEST(card_range_test, apply_to_game) {
    GameModel::Board board{};
    board.getCardPile()->emplace_back(GameModel::CardType::Fascist);
    board.getCardPile()->emplace_back(GameModel::CardType::Fascist);
    board.getCardPile()->emplace_back(GameModel::CardType::Liberal);
    board.getCardPile()->emplace_back(GameModel::CardType::Liberal);
    board.getPolicyState()->emplace(GameModel::CardType::Liberal, 0);
    board.getPolicyState()->emplace(GameModel::CardType::Fascist, 0);

    GameModel::CardRange cardRange{std::make_shared<GameModel::Board>(board), 2};
    EXPECT_TRUE(cardRange.selectForPolicy(GameModel::CardType::Liberal));
    EXPECT_TRUE(cardRange.applyToGame());
    EXPECT_EQ(board.getPolicyState()->find(GameModel::CardType::Liberal)->second, 1);
    EXPECT_EQ(board.getPolicyState()->find(GameModel::CardType::Fascist)->second, 0);
}