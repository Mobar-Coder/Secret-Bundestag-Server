/**
 * @file Board.cpp
 * @author jonas
 * @date 01.12.20
 * Description here TODO
 */

#include <search.h>
#include "Board.hpp"

namespace GameModel {

    Board::Board() : electionTracker(0),
                     policyState(std::make_shared<std::unordered_map<CardType, std::size_t>>()),
                     currentOffice(std::make_shared<std::unordered_map<Office, std::shared_ptr<Player>>>()),
                     pastOffice(std::make_shared<std::unordered_map<Office, std::shared_ptr<Player>>>()),
                     cardPile(std::make_shared<std::vector<CardType>>()),
                     discardPile(std::make_shared<std::vector<CardType>>())
    {
    }

    auto Board::getElectionTracker() const -> size_t {
        return electionTracker;
    }

    auto Board::getPolicyState() const -> std::shared_ptr<std::unordered_map<CardType, std::size_t>> {
        return policyState;
    }

    auto Board::getCurrentOffice() const -> std::shared_ptr<std::unordered_map<Office, std::shared_ptr<Player>>> {
        return currentOffice;
    }

    auto Board::getPastOffice() const -> std::shared_ptr<std::unordered_map<Office, std::shared_ptr<Player>>> {
        return pastOffice;
    }

    auto Board::getCardPile() const -> std::shared_ptr<std::vector<CardType>> {
        return cardPile;
    }

    auto Board::getDiscardPile() const -> std::shared_ptr<std::vector<CardType>> {
        return discardPile;
    }

    auto Board::pushToPolicyState(CardType cardType, std::size_t policyNumber) {
        policyState->emplace(cardType, policyNumber);
    }

    auto Board::incrementElectionTracker() {
        electionTracker++;
    }

    auto Board::resetElectionTracker() {
        electionTracker = 0;
    }

    auto Board::copyCurrentOfficeToPastOffice() {
        pastOffice->clear();
        pastOffice->insert(currentOffice->begin(), currentOffice->end());
    }

    auto Board::addToCurrentOffice(Office office, std::shared_ptr<Player> player) -> bool{
        if (currentOffice->find(office) == currentOffice->end()) {
            currentOffice->emplace(office, player);
            return true;
        }
        else {
            return false;
        }
    }

    auto Board::removeFromCurrentOffice(Office office) -> bool {
        if (currentOffice->find(office) == currentOffice->end()) {
            currentOffice->erase(office);
            return true;
        }
        else {
            return false;
        }
    }

    auto Board::emplaceBackToCardPile(CardType cardType) {
        cardPile->emplace_back(cardType);
    }

    auto Board::emplaceBackToDiscardPile(CardType cardType) {
        discardPile->emplace_back(cardType);
    }

    //TODO Implement
    auto Board::restockCardPile() -> bool {
        return false;
    }
}
