//
// Created by moham on 25/01/2025.
//

#include "Encounter.h"
#include "../Utilities.h"



void Monster::EncounterEvent(std::shared_ptr<Player> player) {
    if(player->Encounter(this->getStrength(),this->getLoot(),this->getDamage())){

        printTurnOutcome(getEncounterWonMessage(*player,this->getLoot()));
    }
    else{
        printTurnOutcome(getEncounterLostMessage(*player, this->getDamage()));
    }
}

int Monster::getStrength() {
    return this->m_strength;
}

int Monster::getLoot() const {
    return m_loot;
}

int Monster::getDamage() const {
    return m_damage;
}

int Monster::getStrengthWithoutUpdate() const {
    return this->m_strength;
}

string Monster::getDescription() const {
    string Message= this->getType() + " (power " + std::to_string(this->getStrengthWithoutUpdate()) +", loot " +
                    std::to_string(this->m_loot) +", damage " + std::to_string(this->m_damage) + ")";
    return Message;
}

string Snail::getType() const {
    return "Snail";
}

string Slime::getType() const {
    return "Slime";
}

int Balrog::getStrength() {
    int oldStrength=m_strength;
    m_strength+=2;
    return oldStrength;
}

int Balrog::getStrengthWithoutUpdate() const {
    return m_strength;
}

string Balrog::getType() const {
    return "Balrog";
}

Pack::~Pack() {
    delete[] m_array;
}

string Pack::getDescription() const {
    string Message= "Pack of " + std::to_string(m_addedCount) + " members (power " +
                    std::to_string(getStrengthWithoutUpdate()) + ", loot " + std::to_string(getLoot()) + ", damage " +
                    std::to_string(getDamage()) + ")";
    return Message;
}

void Pack::Add(std::shared_ptr<Monster> MonsterPtr) {
    if (m_addedCount>m_size) throw std::out_of_range("Out Of Range");
    m_array[m_addedCount++]= MonsterPtr;
}

int Pack::getStrength() {
    int overAllStrength=0;
    for(int i=0;i<m_size;i++){
        overAllStrength+=m_array[i]->getStrength();
    }
    return overAllStrength;
}


int Pack::getLoot() const {
    int overAllLoot=0;
    for(int i=0;i<m_size;i++){
        overAllLoot+=m_array[i]->getLoot();
    }
    return overAllLoot;
}

int Pack::getDamage() const{
    int overAllDamage=0;
    for(int i=0;i<m_size;i++){
        overAllDamage+=m_array[i]->getDamage();
    }
    return overAllDamage;
}

int Pack::getStrengthWithoutUpdate() const {
    int overAllStrength=0;
    for(int i=0;i<m_size;i++){
        overAllStrength+=m_array[i]->getStrengthWithoutUpdate();
    }
    return overAllStrength;
}

string Pack::getType() const {
    return "Pack";
}