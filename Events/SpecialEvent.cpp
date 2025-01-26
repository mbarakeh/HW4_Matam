//
// Created by moham on 25/01/2025.
//

#include "SpecialEvent.h"

string SolarEclipse::getDescription() const {
    return "SolarEclipse";
}

void SolarEclipse::EncounterEvent(std::shared_ptr<Player> player) {
    printTurnOutcome(getSolarEclipseMessage(*player,player->Eclipse()));
}

string PotionsMerchant::getDescription() const {
    return "PotionsMerchant";
}

void PotionsMerchant::EncounterEvent(std::shared_ptr<Player> player) {
    printTurnOutcome(getPotionsPurchaseMessage(
            *player,player->buyPotions(m_cost, m_HealingPoints)));
}