//
// Created by moham on 25/01/2025.
//

#pragma once
#include <string>


#ifndef MATAM4HW4_JOB_H
#define MATAM4HW4_JOB_H
using std::string;


class Job{
protected:
    const std::string m_Name;
    int m_Level, m_Force, m_CurrentHP, m_MaxHP, m_Coins;

public:
    Job()=delete;
    Job(const std::string& Name,int MaxHp=100,int Coins=10)
            :m_Name(Name), m_Level(1), m_Force(5), m_CurrentHP(MaxHp), m_MaxHP(MaxHp), m_Coins(Coins){}
    virtual ~Job()=default;


    virtual const string getJobDescription() const=0;
    string getName() const;
    int getLevel() const;
    void LevelUp();
    int getForce() const;
    virtual int Eclipse();
    int getHealthPoints() const;
    void heal(int healingPoints);
    int getMaxHealthPoints() const;
    int getCoins() const;
    void addToCoins(int CoinsToAdd);
    virtual int getCompatPower() const;
    bool isKnockedOut() const;
    bool JobEncounter(int MonsterPower, int MonsterLoot, int MonsterDamage);
    virtual void EncounterWon(int coinsToAdd);
    void damage(int damagePoints);
};

class Warrior:public Job{
public:
    Warrior(const std::string& Name): Job(Name,150){}
    virtual ~Warrior()=default;

    const string getJobDescription() const override;
    int getCompatPower() const override;
    void EncounterWon(int CoinsToAdd) override;
};

class Archer:public Job{
public:
    Archer(const std::string& Name): Job(Name,100,20){}
    virtual ~Archer()=default;

    const string getJobDescription() const override;
};

class Magician:public Job{
public:
    Magician(const std::string& Name): Job(Name){}
    virtual ~Magician()=default;

    const string getJobDescription() const override;
    int Eclipse() override;
};
#endif //HW4_MATAM_JOB_H
