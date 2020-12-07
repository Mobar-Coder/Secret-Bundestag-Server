/**
 * @file Board.cpp
 * @author jonas
 * @date 01.12.20
 * Description here TODO
 */

#include <algorithm>
#include <search.h>
#include <random>
#include "Board.hpp"

namespace GameModel {

    Board::Board() : electionTracker(0),
                     policyState(std::make_shared<std::unordered_map<CardType, std::size_t>>()),
                     currentOffices(std::make_shared<std::unordered_map<Office, std::shared_ptr<Player>>>()),
                     pastOffices(std::make_shared<std::unordered_map<Office, std::shared_ptr<Player>>>()),
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

    auto Board::getCurrentOffices() const -> std::shared_ptr<std::unordered_map<Office, std::shared_ptr<Player>>> {
        return currentOffices;
    }

    auto Board::getPastOffices() const -> std::shared_ptr<std::unordered_map<Office, std::shared_ptr<Player>>> {
        return pastOffices;
    }

    auto Board::getCardPile() const -> std::shared_ptr<std::vector<CardType>> {
        return cardPile;
    }

    auto Board::getDiscardPile() const -> std::shared_ptr<std::vector<CardType>> {
        return discardPile;
    }

    auto Board::pushToPolicyState(CardType cardType, std::size_t policyNumber) -> void{
        policyState->emplace(cardType, policyNumber);
    }

    auto Board::incrementElectionTracker() -> void {
        electionTracker++;
    }

    auto Board::resetElectionTracker() -> void {
        electionTracker = 0;
    }

    auto Board::copyCurrentOfficesToPastOffices() -> void {
        pastOffices->clear();
        pastOffices->insert(currentOffices->begin(), currentOffices->end());
    }

    auto Board::addToCurrentOffices(Office office, std::shared_ptr<Player> player) -> bool{
        if (currentOffices->find(office) == currentOffices->end()) {
            currentOffices->emplace(office, player);
            return true;
        }
        else {
            return false;
        }
    }

    auto Board::removeFromCurrentOffices(Office office) -> bool {
        if (currentOffices->find(office) == currentOffices->end()) {
            currentOffices->erase(office);
            return true;
        }
        else {
            return false;
        }
    }

    auto Board::emplaceBackToCardPile(CardType cardType) -> void {
        cardPile->emplace_back(cardType);
    }

    auto Board::emplaceBackToDiscardPile(CardType cardType) -> void {
        discardPile->emplace_back(cardType);
    }

    auto Board::restockCardPile() -> void {
        auto rd = std::random_device {};
        auto rng = std::default_random_engine { rd() };
        std::shuffle(discardPile->begin(), discardPile->end(), rng);
        cardPile->insert(cardPile->end(), discardPile->begin(), discardPile->end());
        discardPile->clear();
    }
}
