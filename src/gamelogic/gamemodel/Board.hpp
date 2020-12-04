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

            std::size_t electionTracker;
            std::shared_ptr<std::unordered_map<CardType, std::size_t>> policyState;
            std::shared_ptr<std::unordered_map<Office, std::shared_ptr<Player>>> currentOffice;
            std::shared_ptr<std::unordered_map<Office, std::shared_ptr<Player>>> pastOffice;
            std::shared_ptr<std::vector<CardType>> cardPile;
            std::shared_ptr<std::vector<CardType>> discardPile;

        public:

            Board();

            [[nodiscard]] auto getElectionTracker() const -> size_t;
            [[nodiscard]] auto getPolicyState() const -> std::shared_ptr<std::unordered_map<CardType, std::size_t>>;
            [[nodiscard]] auto getCurrentOffice() const ->
                std::shared_ptr<std::unordered_map<Office, std::shared_ptr<Player>>>;
            [[nodiscard]] auto getPastOffice() const ->
                std::shared_ptr<std::unordered_map<Office, std::shared_ptr<Player>>>;
            [[nodiscard]] auto getCardPile() const -> std::shared_ptr<std::vector<CardType>>;
            [[nodiscard]] auto getDiscardPile() const -> std::shared_ptr<std::vector<CardType>>;

            auto pushToPolicyState(CardType cardType, std::size_t policyNumber);
            auto incrementElectionTracker();
            auto resetElectionTracker();
            auto copyCurrentOfficeToPastOffice();
            auto addToCurrentOffice(Office office, std::shared_ptr<Player> player) -> bool;
            auto removeFromCurrentOffice(Office office) -> bool;
            auto emplaceBackToCardPile(CardType cardType);
            auto emplaceBackToDiscardPile(CardType cardType);
    };
}

#endif // SECRETBUNDESTAGSERVER_BOARD_HPP
