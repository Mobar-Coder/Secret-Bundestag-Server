/**
 * @file Board.hpp
 * @author jonas
 * @date 01.12.20
 * Description here TODO
 */

#ifndef SECRETBUNDESTAGSERVER_BOARD_HPP
#define SECRETBUNDESTAGSERVER_BOARD_HPP

#include <unordered_map>
#include <vector>
#include <memory>
#include "../enum/CardType.hpp"
#include "../enum/Office.hpp"
#include "Player.hpp"

namespace GameModel {

    class Board {

        private:

            std::unordered_map<CardType, std::size_t> policyState;
            std::size_t electionTracker;
            std::unordered_map<Office, std::shared_ptr<Player>> currentOffice;
            std::unordered_map<Office, std::shared_ptr<Player>> pastOffice;
            std::vector<CardType> cardPile;
            std::vector<CardType> discardPile;

        public:

            Board();

            auto getPolicyState() const -> std::shared_ptr<std::unordered_map<CardType, std::size_t>>;
            auto getElectionTracker() const -> size_t;
            auto getCurrentOffice() const -> std::shared_ptr<std::unordered_map<Office, std::shared_ptr<Player>>>;
            auto getPastOffice() const -> std::shared_ptr<std::unordered_map<Office, std::shared_ptr<Player>>>;
            auto getCardPile() const -> std::shared_ptr<std::vector<CardType>>;
            auto getDiscardPile() const -> std::shared_ptr<std::vector<CardType>>;

            auto pushToPolicyState(CardType cardType, std::size_t policyNumber) const;
            auto incrementElectionTracker() const;
            auto copyCurrentOfficeToPastOffice() const;
            auto pushToCurrentOffice(Office office, std::shared_ptr<Player> player) const;
            auto removeFromCurrentOffice(Office office, std::shared_ptr<Player> player) const -> bool;
            auto pushToCardPile(CardType cardType) const;
            auto emplaceBackToCardPile(CardType cardType) const;
            auto pushToDiscardPile(CardType cardType) const;
            auto emplaceBackToDiscardPile(CardType cardType) const;
    };
}

#endif // SECRETBUNDESTAGSERVER_BOARD_HPP
