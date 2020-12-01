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

    auto Board::getPolicyState() const -> std::shared_ptr<std::unordered_map<CardType, std::size_t>> {
        return std::make_shared<std::unordered_map<CardType, std::size_t>>(policyState);
    }

    auto Board::getElectionTracker() const -> size_t {
        return electionTracker;
    }

    auto Board::getCurrentOffice() const -> std::shared_ptr<std::unordered_map<Office, std::shared_ptr<Player>>> {
        return std::make_shared<std::unordered_map<Office, std::shared_ptr<Player>>>(currentOffice);
    }

    auto Board::getPastOffice() const -> std::shared_ptr<std::unordered_map<Office, std::shared_ptr<Player>>> {
        return std::make_shared<std::unordered_map<Office, std::shared_ptr<Player>>>(pastOffice);
    }

    auto Board::getCardPile() const -> std::shared_ptr<std::vector<CardType>> {
        return std::make_shared<std::vector<CardType>>(cardPile);
    }

    auto Board::getDiscardPile() const -> std::shared_ptr<std::vector<CardType>> {
        return std::make_shared<std::vector<CardType>>(discardPile);
    }

    auto Board::pushToPolicyState(CardType cardType, std::size_t policyNumber) const {
        return nullptr;
    }

    auto Board::incrementElectionTracker() const {
        return nullptr;
    }

    auto Board::copyCurrentOfficeToPastOffice() const {
        return nullptr;
    }

    auto Board::pushToCurrentOffice(Office office, std::shared_ptr<Player> player) const {
        return nullptr;
    }

    auto Board::removeFromCurrentOffice(Office office, std::shared_ptr<Player> player) const -> bool {
        return false;
    }

    auto Board::pushToCardPile(CardType cardType) const {
        return nullptr;
    }

    auto Board::emplaceBackToCardPile(CardType cardType) const {
        return nullptr;
    }

    auto Board::pushToDiscardPile(CardType cardType) const {
        return nullptr;
    }

    auto Board::emplaceBackToDiscardPile(CardType cardType) const {
        return nullptr;
    }
}
