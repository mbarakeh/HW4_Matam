//
// Created by moham on 25/01/2025.
//
#pragma once

#ifndef MATAM4HW4_MONSTER_H
#define MATAM4HW4_MONSTER_H

#include "Event.h"
#include <stdexcept>



class Monster: public Event{
protected:
    int m_strength, m_loot, m_damage;
public:

    Monster()=default;
    Monster(int strength, int loot ,int damage): m_strength(strength), m_loot(loot), m_damage(damage){}
    virtual void EncounterEvent(std::shared_ptr<Player> player) override ;
    virtual string getDescription() const override ;
    virtual string getType() const =0;

    virtual int getStrength();
    virtual int getStrengthWithoutUpdate() const;
    virtual int getLoot() const;
    virtual int getDamage() const;
};

class Snail:public Monster{
public:
    Snail():Monster(5,2,10){}
    virtual ~Snail()=default;

    string getType() const override;
};

class Slime:public Monster{
public:
    Slime(): Monster(12,5,25){}
    virtual ~Slime()=default;

    string getType() const override;
};

class Balrog:public Monster{
public:
    Balrog():Monster(15, 100, 9001){}
    virtual ~Balrog()=default;

    int getStrength() override;
    int getStrengthWithoutUpdate() const override;
    string getType() const override;
};

class Pack:public Monster{
    std::shared_ptr<Monster> * m_array;
    int m_size;
    int m_addedCount;
public:
    Pack(int size): Monster(), m_array(new std::shared_ptr<Monster>  [size]()), m_size(size), m_addedCount(0){}
    virtual ~Pack();

    string getDescription() const override;
    void Add(std::shared_ptr<Monster> MonsterPtr);
    int getStrength() override;
    int getLoot() const override;
    int getDamage() const override;
    int getStrengthWithoutUpdate() const override;
    string getType() const override;

};

#endif //HW4_MATAM_ENCOUNTER_H
