//
// Created by moham on 25/01/2025.
//
#pragma once

#ifndef MATAM4HW4_CHARACTER_H
#define MATAM4HW4_CHARACTER_H

#include <string>
using std::string;
#include "Job.h"

class Character{
protected:
    Job* m_Job;

public:
    Character()=delete;
    Character(Job* Job): m_Job(Job){}
    virtual ~Character();

    string getName() const;
    int getLevel() const;
    int getForce() const;
    int getHealthPoints() const;
    int getCoins() const;

    bool CharacterEncounter(int MonsterPower, int MonsterLoot, int MonsterDamage);
    int Eclipse();

    int getCompatPower() const;
    bool isKnockedOut() const;

    string CreateMessage();
    virtual string getCharacterDescription() const=0;
    virtual int buyPotions(int cost, int HealingPoints) =0;
};

class Responsible:public Character{

public:
    Responsible(Job* Job): Character(Job){}
    string getCharacterDescription() const override;
    int buyPotions(int cost, int HealingPoints) override;
};

class RiskTaking: public Character{
public:
    RiskTaking(Job* Job): Character(Job){}
    string getCharacterDescription() const override;
    int buyPotions(int cost, int HealingPoints) override;
};
#endif //HW4_MATAM_CHARACTER_H
