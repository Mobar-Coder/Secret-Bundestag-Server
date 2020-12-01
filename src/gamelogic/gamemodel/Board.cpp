/**
 * @file Board.cpp
 * @author jonas
 * @date 01.12.20
 * Description here TODO
 */

#include "Board.hpp"

namespace GameModel {

    Board::Board() {

    }

    void Board::setPolicyState(const std::unordered_map<CardType, std::size_t> &policyState) {
        Board::policyState = policyState;
    }

    size_t Board::getElectionTracker() const {
        return electionTracker;
    }

    void Board::setElectionTracker(size_t electionTracker) {
        Board::electionTracker = electionTracker;
    }

    const std::unordered_map<Office, Player> &Board::getCurrentOffice() const {
        return currentOffice;
    }

    void Board::setCurrentOffice(const std::unordered_map<Office, Player> &currentOffice) {
        Board::currentOffice = currentOffice;
    }

    const std::unordered_map<Office, std::optional<Player>> &Board::getPastOffice() const {
        return pastOffice;
    }

    void Board::setPastOffice(const std::unordered_map<Office, std::optional<Player>> &pastOffice) {
        Board::pastOffice = pastOffice;
    }

    const std::vector<CardType> &Board::getCardPile() const {
        return cardPile;
    }

    void Board::setCardPile(const std::vector<CardType> &cardPile) {
        Board::cardPile = cardPile;
    }

    const std::vector<CardType> &Board::getDiscardPile() const {
        return discardPile;
    }

    void Board::setDiscardPile(const std::vector<CardType> &discardPile) {
        Board::discardPile = discardPile;
    }

    void Board::cardPileEmplaceBack(const CardType cardType) {
        cardPile.emplace_back(cardType);
    }
}
