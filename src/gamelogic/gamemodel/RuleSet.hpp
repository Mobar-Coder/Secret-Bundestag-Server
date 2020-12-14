/**
 * @file RuleSet.hpp.h
 * @author jonas
 * @date 14.12.20
 * Description here TODO
 */

#ifndef SECRETBUNDESTAGSERVER_RULESET_HPP
#define SECRETBUNDESTAGSERVER_RULESET_HPP

#include <unordered_map>
#include "../enum/CardType.hpp"
#include "../enum/Fraction.hpp"

namespace GameModel {

    class RuleSet {
        public:
            std::unordered_map<CardType, std::size_t> cardsInGame;
            std::unordered_map<Fraction, std::pair<CardType, std::size_t>> numCardsToWin;
            std::unordered_map<Fraction, std::size_t> numPlayersPerFraction;

    };
}

#endif //SECRETBUNDESTAGSERVER_RULESET_HPP
