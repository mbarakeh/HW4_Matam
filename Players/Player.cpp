//
// Created by moham on 25/01/2025.
//

#include "Player.h"

Player::~Player() {
    delete m_Character;
}

bool Player::Encounter(int MonsterPower, int MonsterLoot, int MonsterDamage) {
    return m_Character->CharacterEncounter(MonsterPower ,MonsterLoot ,MonsterDamage);
}

int Player::buyPotions(int cost, int HealingPoints) {
    return m_Character->buyPotions(cost, HealingPoints);
}

int Player::Eclipse() {
    return m_Character->Eclipse();
}

bool Player::isKnockedOut() const {
    return m_Character->isKnockedOut();
}

string Player::getDescription() const {
    return m_Character->CreateMessage();
}

string Player::getName() const {
    return m_Character->getName();
}

int Player::getLevel() const {
    return m_Character->getLevel();
}

int Player::getForce() const {
    return m_Character->getForce();
}

int Player::getHealthPoints() const {
    return m_Character->getHealthPoints();
}

int Player::getCoins() const {
    return m_Character->getCoins();
}