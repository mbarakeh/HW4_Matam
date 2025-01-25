//
// Created by moham on 25/01/2025.
//
#include "Job.h"



string Job::getName() const {
    return m_Name;
}

int Job::getLevel() const {
    return m_Level;
}

void Job::LevelUp() {
    this->m_Level+=1;
}

int Job::getForce() const {
    return m_Force;
}

int Job::Eclipse() {
    if(m_Force>0){
        m_Force-=1;
        return -1;
    }

    return 0;
}

int Job::getHealthPoints() const {
    return m_CurrentHP;
}

void Job::heal(int healingPoints) {
    if (m_CurrentHP+ healingPoints>= m_MaxHP){
        m_CurrentHP= m_MaxHP;
    }
    else{
        m_CurrentHP+=healingPoints;
    }
}

int Job::getMaxHealthPoints() const {
    return m_MaxHP;
}

int Job::getCoins() const {
    return m_Coins;
}

void Job::addToCoins(int CoinsToAdd) {
    m_Coins+=CoinsToAdd;
}

int Job::getCompatPower() const {
    return m_Force + m_Level;
}

bool Job::isKnockedOut() const {
    return (m_CurrentHP==0);
}

void Job::EncounterWon(int coinsToAdd) {
    this->addToCoins(coinsToAdd);
}

void Job::damage(int damagePoints) {
    if (this->m_CurrentHP-damagePoints<=0)
    {
        this->m_CurrentHP=0;
    }
    else{
        this->m_CurrentHP-=damagePoints;
    }
}

const string Warrior::getJobDescription() const {
    return "Warrior";
}

int Warrior::getCompatPower() const {
    return 2*m_Force + m_Level;
}

bool Job::JobEncounter(int MonsterPower, int MonsterLoot, int MonsterDamage) {
    if(getCompatPower()>MonsterPower){
        this->EncounterWon(MonsterLoot);
        this->LevelUp();
        return true;
    } else{
        this->damage(MonsterDamage);
        return false;
    }
}

void Warrior::EncounterWon(int CoinsToAdd) {
    this->addToCoins(CoinsToAdd);
    this->damage(10);
}


const string Archer::getJobDescription() const {
    return "Archer";
}


const string Magician::getJobDescription() const {
    return "Magician";
}

int Magician::Eclipse() {
    m_Force+=1;
    return 1;
}
