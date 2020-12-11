//
// Created by bjorn on 07.12.20.
//

#include <gtest/gtest.h>
#include "gamelogic/gamemodel/CardRange.hpp"

//TODO Test für mehr als 1 Karte wäheln und für falsche Karte
TEST(GameModel_CardRange, select_policy) {
    GameModel::Board board{};

    GameModel::CardRange cardRange{board, 1};
    EXPECT_TRUE(cardRange.selectForPolicy(GameModel::CardType::Fascist));
    EXPECT_FALSE(cardRange.selectForPolicy(GameModel::CardType::Liberal));
}

TEST(card_range_test, constructor0) {
    GameModel::Board board{};

    GameModel::CardRange cardRange{board, 2};
    EXPECT_EQ(board.getCardPile().at(0), GameModel::CardType::Liberal);
    EXPECT_EQ(board.getCardPile().at(6), GameModel::CardType::Fascist);
    EXPECT_EQ(board.getCardPile().size(), 15);
}

TEST(card_range_test, destructor) {
    GameModel::Board board{};

    {
        GameModel::CardRange cardRange{board, 2};
        EXPECT_EQ(board.getCardPile().size(), 15);
    }

    EXPECT_EQ(board.getCardPile().size(), 17);
}

TEST(card_range_test, discard_card) {
    GameModel::Board board{};

    GameModel::CardRange cardRange{board, 2};
    EXPECT_TRUE(cardRange.discard(GameModel::CardType::Fascist));
    EXPECT_FALSE(cardRange.discard(GameModel::CardType::Liberal));
}

TEST(card_range_test, apply_to_game0) {
    GameModel::Board board{};
    GameModel::CardRange cardRange{board, 3};

    EXPECT_TRUE(cardRange.discard(GameModel::CardType::Fascist));
    EXPECT_TRUE(cardRange.discard(GameModel::CardType::Fascist));
    EXPECT_TRUE(cardRange.selectForPolicy(GameModel::CardType::Fascist));
    EXPECT_EQ(board.getDiscardPile().size(), 0);
    EXPECT_TRUE(cardRange.applyToGame());

    EXPECT_EQ(board.getNumberOfPolicy(GameModel::CardType::Fascist), 1);
    EXPECT_EQ(board.getNumberOfPolicy(GameModel::CardType::Liberal), 0);
    EXPECT_EQ(board.getCardPile().size(), 14);
    EXPECT_EQ(board.getDiscardPile().size(), 3);
}

TEST(card_range_test, apply_to_game1) {
    GameModel::Board board{};
    GameModel::CardRange cardRange{board, 3};

    EXPECT_TRUE(cardRange.discard(GameModel::CardType::Fascist));
    EXPECT_TRUE(cardRange.selectForPolicy(GameModel::CardType::Fascist));
    EXPECT_EQ(board.getDiscardPile().size(), 0);
    EXPECT_TRUE(cardRange.applyToGame());

    EXPECT_EQ(board.getNumberOfPolicy(GameModel::CardType::Fascist), 1);
    EXPECT_EQ(board.getNumberOfPolicy(GameModel::CardType::Liberal), 0);
    EXPECT_EQ(board.getCardPile().size(), 14);
    EXPECT_EQ(board.getDiscardPile().size(), 3);
}