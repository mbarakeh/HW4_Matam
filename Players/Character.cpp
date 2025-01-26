//
// Created by moham on 25/01/2025.
//

#include "Character.h"

Character::~Character() {
    delete m_Job;
}

string Character::getName() const {
    return m_Job->getName();
}

int Character::getLevel() const {
    return m_Job->getLevel();
}

int Character::getForce() const {
    return m_Job->getForce();
}

int Character::getHealthPoints() const {
    return m_Job->getHealthPoints();
}

int Character::getCoins() const {
    return m_Job->getCoins();
}

int Character::getCompatPower() const {
    return m_Job->getCompatPower();
}

bool Character::isKnockedOut() const {
    return m_Job->isKnockedOut();
}

bool Character::CharacterEncounter(int MonsterPower, int MonsterLoot, int MonsterDamage) {
    return m_Job->JobEncounter(MonsterPower,MonsterLoot,MonsterDamage);
}

int Character::Eclipse() {
    return m_Job->Eclipse();
}

string Character::CreateMessage() {
    string message= m_Job->getName() + ", " + m_Job->getJobDescription() + " with " + getCharacterDescription()
                    + " character (level " + std::to_string(m_Job->getLevel()) + ", force " +
                    std::to_string(m_Job->getForce()) + ")" ;
    return message;
}

string Responsible::getCharacterDescription() const {
    return "Responsible";
}

int Responsible::buyPotions(int cost, int HealingPoints) {
    int amount=0;
    while (m_Job->getCoins()>=5 && m_Job->getHealthPoints()!=m_Job->getMaxHealthPoints()){
        amount++;
        m_Job->addToCoins(-cost);
        m_Job->heal(HealingPoints);
    }
    return amount;
}

string RiskTaking::getCharacterDescription() const {
    return "RiskTaking";
}

int RiskTaking::buyPotions(int cost, int HealingPoints) {
    int amount=0;
    if (m_Job->getHealthPoints()<50){
        if (m_Job->getCoins()>=5){
            m_Job->heal(HealingPoints);
            m_Job->addToCoins(-cost);
            amount=1;
        }
    }
    return amount;
}
