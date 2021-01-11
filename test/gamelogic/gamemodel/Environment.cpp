//
// Created by bjorn on 09.12.20.
//

#include <gtest/gtest.h>

#include "gamelogic/gamemodel/Environment.hpp"

namespace GameModel {
    class EnvironmentTest : public Environment {
        public:
            EnvironmentTest(std::vector<std::shared_ptr<Player>> players) : Environment(players) {}

            using Environment::getBoard;
    };

}
TEST(GameModel_Environment, draw_n_cards0) {
    GameModel::Player player("Björn", GameModel::Fraction::LIBERAL_PARTY, GameModel::Role::NONE, 0);
    std::vector<std::shared_ptr<GameModel::Player>> players;
    players.emplace_back(std::make_shared<GameModel::Player>(player));
    GameModel::EnvironmentTest environment(players);

    EXPECT_EQ(environment.getBoard().getCardPile().size(), 17);
    auto cardRange = environment.drawNCards(3);
    EXPECT_ANY_THROW(environment.drawNCards(18));
    EXPECT_EQ(environment.getBoard().getCardPile().size(), 14);
    EXPECT_TRUE(cardRange.selectForPolicy(GameModel::CardType::FASCIST));
    EXPECT_TRUE(cardRange.applyToGame());
    EXPECT_EQ(environment.getBoard().getCardPile().size(), 16);
    EXPECT_EQ(environment.getBoard().getDiscardPile().size(), 0);
    EXPECT_EQ(environment.getBoard().getNumberOfPolicy(GameModel::CardType::FASCIST), 1);
    EXPECT_EQ(environment.getBoard().getNumberOfPolicy(GameModel::CardType::LIBERAL), 0);
}

TEST(GameModel_Environment, draw_n_cards1) {
    GameModel::Player player("Björn", GameModel::Fraction::LIBERAL_PARTY, GameModel::Role::NONE, 0);
    std::vector<std::shared_ptr<GameModel::Player>> players;
    players.emplace_back(std::make_shared<GameModel::Player>(player));
    GameModel::EnvironmentTest environment(players);

    EXPECT_EQ(environment.getBoard().getCardPile().size(), 17);
    auto cardRange = environment.drawNCards(15);
    EXPECT_EQ(environment.getBoard().getCardPile().size(), 2);
    EXPECT_TRUE(cardRange.selectForPolicy(GameModel::CardType::FASCIST));
    EXPECT_TRUE(cardRange.discardRemainingCards());
    EXPECT_TRUE(cardRange.applyToGame());
    EXPECT_EQ(environment.getBoard().getCardPile().size(), 2);
    EXPECT_EQ(environment.getBoard().getDiscardPile().size(), 14);
    EXPECT_EQ(environment.getBoard().getNumberOfPolicy(GameModel::CardType::FASCIST), 1);
    EXPECT_EQ(environment.getBoard().getNumberOfPolicy(GameModel::CardType::LIBERAL), 0);

    auto cardRange1 = environment.drawNCards(3);
    EXPECT_EQ(environment.getBoard().getCardPile().size(), 13);
    EXPECT_EQ(environment.getBoard().getDiscardPile().size(), 0);
}

TEST(GameModel_Environment, get_players) {
    GameModel::Player player1("Björn", GameModel::Fraction::LIBERAL_PARTY, GameModel::Role::NONE, 0);
    GameModel::Player player2("Test", GameModel::Fraction::FASCIST_PARTY, GameModel::Role::HITLER, 0);
    std::vector<std::shared_ptr<GameModel::Player>> players;
    players.emplace_back(std::make_shared<GameModel::Player>(player1));
    players.emplace_back(std::make_shared<GameModel::Player>(player2));
    GameModel::Environment environment(players);

    auto player_returned = environment.getPlayers();
    EXPECT_EQ(player_returned.size(), 2);
}

TEST(GameModel_Environment, increment_election_tracker) {
    GameModel::Player player("Björn", GameModel::Fraction::LIBERAL_PARTY, GameModel::Role::NONE, 0);
    std::vector<std::shared_ptr<GameModel::Player>> players;
    players.emplace_back(std::make_shared<GameModel::Player>(player));
    GameModel::EnvironmentTest environment(players);

    EXPECT_EQ(environment.getBoard().getElectionTracker(), 0);
    environment.incrementElectionTracker();
    EXPECT_EQ(environment.getBoard().getElectionTracker(), 1);
    environment.incrementElectionTracker();
    environment.incrementElectionTracker();
    EXPECT_EQ(environment.getBoard().getElectionTracker(), 3);
}

TEST(GameModel_Environment, reset_election_tracker) {
    GameModel::Player player("Björn", GameModel::Fraction::LIBERAL_PARTY, GameModel::Role::NONE, 0);
    std::vector<std::shared_ptr<GameModel::Player>> players;
    players.emplace_back(std::make_shared<GameModel::Player>(player));
    GameModel::EnvironmentTest environment(players);

    EXPECT_EQ(environment.getBoard().getElectionTracker(), 0);
    environment.incrementElectionTracker();
    EXPECT_EQ(environment.getBoard().getElectionTracker(), 1);
    environment.incrementElectionTracker();
    environment.incrementElectionTracker();
    EXPECT_EQ(environment.getBoard().getElectionTracker(), 3);
    environment.resetElectionTracker();
    EXPECT_EQ(environment.getBoard().getElectionTracker(), 0);
}

TEST(GameModel_Environment, kill_player) {
    GameModel::Player player1("Björn", GameModel::Fraction::LIBERAL_PARTY, GameModel::Role::NONE, 0);
    GameModel::Player player2("Test", GameModel::Fraction::FASCIST_PARTY, GameModel::Role::HITLER, 0);
    std::vector<std::shared_ptr<GameModel::Player>> players;
    players.emplace_back(std::make_shared<GameModel::Player>(player1));
    players.emplace_back(std::make_shared<GameModel::Player>(player2));
    GameModel::Environment environment(players);

    environment.killPlayer(players[0]);
    EXPECT_FALSE(environment.getPlayers()[0]->isAlive());
    EXPECT_TRUE(environment.getPlayers()[1]->isAlive());
}

TEST(GameModel_Environment, auto_select_president0) {
    GameModel::Player player1("Test0", GameModel::Fraction::LIBERAL_PARTY, GameModel::Role::NONE, 0);
    GameModel::Player player2("Test1", GameModel::Fraction::FASCIST_PARTY, GameModel::Role::HITLER, 0);
    GameModel::Player player3("Test2", GameModel::Fraction::FASCIST_PARTY, GameModel::Role::NONE, 0);
    std::vector<std::shared_ptr<GameModel::Player>> players;
    players.emplace_back(std::make_shared<GameModel::Player>(player1));
    players.emplace_back(std::make_shared<GameModel::Player>(player2));
    GameModel::EnvironmentTest environment(players);

    auto president1 = environment.getBoard().getPlayerInCurrentOffice(GameModel::Office::PRESIDENT);
    EXPECT_TRUE(president1.has_value());
    environment.autoSelectPresident();

    auto president2 = environment.getBoard().getPlayerInCurrentOffice(GameModel::Office::PRESIDENT);
    EXPECT_TRUE(president2.has_value());
    EXPECT_NE(president1, president2);
}

TEST(GameModel_Environment, auto_select_president1) {
    GameModel::Player player1("Test0", GameModel::Fraction::LIBERAL_PARTY, GameModel::Role::NONE, 0);
    GameModel::Player player2("Test1", GameModel::Fraction::FASCIST_PARTY, GameModel::Role::HITLER, 0);
    GameModel::Player player3("Test2", GameModel::Fraction::FASCIST_PARTY, GameModel::Role::NONE, 0);
    std::vector<std::shared_ptr<GameModel::Player>> players;
    players.emplace_back(std::make_shared<GameModel::Player>(player1));
    players.emplace_back(std::make_shared<GameModel::Player>(player2));
    players.emplace_back(std::make_shared<GameModel::Player>(player3));
    GameModel::EnvironmentTest environment(players);

    auto president1 = environment.getBoard().getPlayerInCurrentOffice(GameModel::Office::PRESIDENT);
    EXPECT_TRUE(president1.has_value());
    environment.autoSelectPresident();

    EXPECT_TRUE(environment.killPlayer(players[0]));
    EXPECT_TRUE(environment.killPlayer(players[1]));
    EXPECT_TRUE(environment.killPlayer(players[2]));
    EXPECT_FALSE(environment.killPlayer(players[3]));
    EXPECT_ANY_THROW(environment.autoSelectPresident());
}

TEST(GameModel_Environment, set_chancelor_candidate) {
    GameModel::Player player1("Test0", GameModel::Fraction::LIBERAL_PARTY, GameModel::Role::NONE, 0);
    GameModel::Player player2("Test1", GameModel::Fraction::FASCIST_PARTY, GameModel::Role::HITLER, 0);
    GameModel::Player player3("Test2", GameModel::Fraction::FASCIST_PARTY, GameModel::Role::NONE, 0);
    std::vector<std::shared_ptr<GameModel::Player>> players;
    players.emplace_back(std::make_shared<GameModel::Player>(player1));
    players.emplace_back(std::make_shared<GameModel::Player>(player2));
    players.emplace_back(std::make_shared<GameModel::Player>(player3));
    GameModel::EnvironmentTest environment(players);

    EXPECT_FALSE(environment.getChancellor().has_value());
    EXPECT_FALSE(environment.electChancellor());
    environment.setCandidateForChancellor(players[1]);
    EXPECT_TRUE(environment.getBoard().getPlayerInCurrentOffice(GameModel::Office::CANDIDATE).has_value());
    EXPECT_EQ(player2.getName(),
              environment.getBoard().getPlayerInCurrentOffice(GameModel::Office::CANDIDATE).value()->getName());

    environment.setCandidateForChancellor(players[2]);
    EXPECT_TRUE(environment.getBoard().getPlayerInCurrentOffice(GameModel::Office::CANDIDATE).has_value());
    EXPECT_EQ(player3.getName(),
              environment.getBoard().getPlayerInCurrentOffice(GameModel::Office::CANDIDATE).value()->getName());
}

TEST(GameModel_Environment, elect_chancelor) {
    GameModel::Player player1("Test0", GameModel::Fraction::LIBERAL_PARTY, GameModel::Role::NONE, 0);
    GameModel::Player player2("Test1", GameModel::Fraction::FASCIST_PARTY, GameModel::Role::HITLER, 0);
    GameModel::Player player3("Test2", GameModel::Fraction::FASCIST_PARTY, GameModel::Role::NONE, 0);
    std::vector<std::shared_ptr<GameModel::Player>> players;
    players.emplace_back(std::make_shared<GameModel::Player>(player1));
    players.emplace_back(std::make_shared<GameModel::Player>(player2));
    players.emplace_back(std::make_shared<GameModel::Player>(player3));
    GameModel::EnvironmentTest environment(players);

    EXPECT_FALSE(environment.getChancellor().has_value());
    EXPECT_FALSE(environment.electChancellor());
    environment.setCandidateForChancellor(players[1]);
    EXPECT_TRUE(environment.electChancellor());
    EXPECT_TRUE(environment.getChancellor().has_value());
}

TEST(GameModel_Environment, reset_past_offices) {
    GameModel::Player player1("Test0", GameModel::Fraction::LIBERAL_PARTY, GameModel::Role::NONE, 0);
    GameModel::Player player2("Test1", GameModel::Fraction::FASCIST_PARTY, GameModel::Role::HITLER, 0);
    GameModel::Player player3("Test2", GameModel::Fraction::FASCIST_PARTY, GameModel::Role::NONE, 0);
    std::vector<std::shared_ptr<GameModel::Player>> players;
    players.emplace_back(std::make_shared<GameModel::Player>(player1));
    players.emplace_back(std::make_shared<GameModel::Player>(player2));
    players.emplace_back(std::make_shared<GameModel::Player>(player3));
    GameModel::EnvironmentTest environment(players);

    EXPECT_FALSE(environment.getChancellor().has_value());
    EXPECT_FALSE(environment.electChancellor());
    environment.setCandidateForChancellor(players[1]);
    EXPECT_TRUE(environment.electChancellor());
    EXPECT_TRUE(environment.getChancellor().has_value());
    EXPECT_FALSE(environment.getBoard().getPlayerInPastOffice(GameModel::Office::CANDIDATE).has_value());
    environment.safeToPastOffices();
    EXPECT_TRUE(environment.getBoard().getPlayerInPastOffice(GameModel::Office::CANDIDATE).has_value());
    environment.resetPastOffices();
    EXPECT_FALSE(environment.getBoard().getPlayerInPastOffice(GameModel::Office::CANDIDATE).has_value());
}

TEST(GameModel_Environment, get_president) {
    GameModel::Player player1("Test0", GameModel::Fraction::LIBERAL_PARTY, GameModel::Role::NONE, 0);
    GameModel::Player player2("Test1", GameModel::Fraction::FASCIST_PARTY, GameModel::Role::HITLER, 0);
    GameModel::Player player3("Test2", GameModel::Fraction::FASCIST_PARTY, GameModel::Role::NONE, 0);
    std::vector<std::shared_ptr<GameModel::Player>> players;
    players.emplace_back(std::make_shared<GameModel::Player>(player1));
    players.emplace_back(std::make_shared<GameModel::Player>(player2));
    players.emplace_back(std::make_shared<GameModel::Player>(player3));
    GameModel::EnvironmentTest environment(players);
    EXPECT_TRUE(environment.getPresident());
}

TEST(GameModel_Environment, get_chancelor) {
    GameModel::Player player1("Test0", GameModel::Fraction::LIBERAL_PARTY, GameModel::Role::NONE, 0);
    GameModel::Player player2("Test1", GameModel::Fraction::FASCIST_PARTY, GameModel::Role::HITLER, 0);
    GameModel::Player player3("Test2", GameModel::Fraction::FASCIST_PARTY, GameModel::Role::NONE, 0);
    std::vector<std::shared_ptr<GameModel::Player>> players;
    players.emplace_back(std::make_shared<GameModel::Player>(player1));
    players.emplace_back(std::make_shared<GameModel::Player>(player2));
    players.emplace_back(std::make_shared<GameModel::Player>(player3));
    GameModel::EnvironmentTest environment(players);
    EXPECT_FALSE(environment.getChancellor().has_value());

    environment.setCandidateForChancellor(players[1]);
    EXPECT_TRUE(environment.electChancellor());
    EXPECT_TRUE(environment.getChancellor().has_value());
}

TEST(GameModel_Environment, get_party) {
    GameModel::Player player1("Test0", GameModel::Fraction::LIBERAL_PARTY, GameModel::Role::NONE, 0);
    GameModel::Player player2("Test1", GameModel::Fraction::FASCIST_PARTY, GameModel::Role::HITLER, 0);
    GameModel::Player player3("Test2", GameModel::Fraction::FASCIST_PARTY, GameModel::Role::NONE, 0);
    std::vector<std::shared_ptr<GameModel::Player>> players;
    players.emplace_back(std::make_shared<GameModel::Player>(player1));
    players.emplace_back(std::make_shared<GameModel::Player>(player2));
    players.emplace_back(std::make_shared<GameModel::Player>(player3));
    GameModel::EnvironmentTest environment(players);

    EXPECT_EQ(environment.getParty(GameModel::Fraction::FASCIST_PARTY).size(), 2);
    EXPECT_EQ(environment.getParty(GameModel::Fraction::LIBERAL_PARTY).size(), 1);
}

TEST(GameModel_Environment, number_card_piles0) {
    GameModel::Player player1("Test0", GameModel::Fraction::LIBERAL_PARTY, GameModel::Role::NONE, 0);
    std::vector<std::shared_ptr<GameModel::Player>> players;
    players.emplace_back(std::make_shared<GameModel::Player>(player1));
    GameModel::EnvironmentTest environment(players);

    EXPECT_EQ(environment.getNumberCardsCardPile(), 17);
    EXPECT_EQ(environment.getNumberCardsDiscardPile(), 0);

    auto cardRange = environment.drawNCards(7);
    EXPECT_EQ(environment.getNumberCardsCardPile(), 10);
    EXPECT_EQ(environment.getNumberCardsDiscardPile(), 0);
    EXPECT_TRUE(cardRange.selectForPolicy(GameModel::CardType::FASCIST));
    EXPECT_TRUE(cardRange.discardRemainingCards());
    EXPECT_TRUE(cardRange.applyToGame());
    EXPECT_EQ(environment.getNumberCardsCardPile(), 10);
    EXPECT_EQ(environment.getNumberCardsDiscardPile(), 6);
}

TEST(GameModel_Environment, number_of_policies) {
    GameModel::Player player("Björn", GameModel::Fraction::LIBERAL_PARTY, GameModel::Role::NONE, 0);
    std::vector<std::shared_ptr<GameModel::Player>> players;
    players.emplace_back(std::make_shared<GameModel::Player>(player));
    GameModel::EnvironmentTest environment(players);

    {
        auto cardRange = environment.drawNCards(6);
        EXPECT_TRUE(cardRange.selectForPolicy(GameModel::CardType::FASCIST));
        EXPECT_TRUE(cardRange.discardRemainingCards());
        EXPECT_TRUE(cardRange.applyToGame());
        EXPECT_EQ(environment.getNumberOfPlayedPolicies(GameModel::CardType::FASCIST), 1);
        EXPECT_EQ(environment.getNumberOfPlayedPolicies(GameModel::CardType::LIBERAL), 0);
    }

    {
        auto cardRange = environment.drawNCards(3);
        EXPECT_TRUE(cardRange.selectForPolicy(GameModel::CardType::FASCIST));
        EXPECT_TRUE(cardRange.discardRemainingCards());
        EXPECT_TRUE(cardRange.applyToGame());
        EXPECT_EQ(environment.getNumberOfPlayedPolicies(GameModel::CardType::FASCIST), 2);
        EXPECT_EQ(environment.getNumberOfPlayedPolicies(GameModel::CardType::LIBERAL), 0);
    }

    {
        auto cardRange = environment.drawNCards(6);
        EXPECT_TRUE(cardRange.selectForPolicy(GameModel::CardType::LIBERAL));
        EXPECT_TRUE(cardRange.discardRemainingCards());
        EXPECT_TRUE(cardRange.applyToGame());
        EXPECT_EQ(environment.getNumberOfPlayedPolicies(GameModel::CardType::FASCIST), 2);
        EXPECT_EQ(environment.getNumberOfPlayedPolicies(GameModel::CardType::LIBERAL), 1);
    }
    {
        auto cardRange = environment.drawNCards(2);
        EXPECT_TRUE(cardRange.selectForPolicy(GameModel::CardType::LIBERAL));
        EXPECT_TRUE(cardRange.discardRemainingCards());
        EXPECT_TRUE(cardRange.applyToGame());
        EXPECT_EQ(environment.getNumberOfPlayedPolicies(GameModel::CardType::FASCIST), 2);
        EXPECT_EQ(environment.getNumberOfPlayedPolicies(GameModel::CardType::LIBERAL), 2);
    }
}