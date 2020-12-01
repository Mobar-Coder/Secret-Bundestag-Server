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
            std::unordered_map<Office, Player> currentOffice;
            std::unordered_map<Office, std::optional<Player>> pastOffice;
            std::vector<CardType> cardPile;
            std::vector<CardType> discardPile;

        public:

            Board();

            auto getPolicyState() const -> std::shared_ptr<std::unordered_map<CardType, std::size_t>>;




            void setPolicyState(const std::unordered_map<CardType, std::size_t> &policyState);
            size_t getElectionTracker() const;
            void setElectionTracker(size_t electionTracker);
            const std::unordered_map<Office, Player> &getCurrentOffice() const;
            void setCurrentOffice(const std::unordered_map<Office, Player> &currentOffice);
            const std::unordered_map<Office, std::optional<Player>> &getPastOffice() const;
            void setPastOffice(const std::unordered_map<Office, std::optional<Player>> &pastOffice);
            const std::vector<CardType> &getCardPile() const;
            void setCardPile(const std::vector<CardType> &cardPile);
            const std::vector<CardType> &getDiscardPile() const;
            void setDiscardPile(const std::vector<CardType> &discardPile);

            void cardPileEmplaceBack(const CardType cardType);

        private:

    };
}

#endif // SECRETBUNDESTAGSERVER_BOARD_HPP
