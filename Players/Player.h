
#pragma once

#include <string>
#include "Character.h"

using std::string;

class Player {

    Character* m_Character;
public:

    Player()=delete;
    Player(Character* character): m_Character(character){}
    ~Player();

    bool Encounter(int MonsterPower, int MonsterLoot, int MonsterDamage);
    int buyPotions(int cost, int HealingPoints);
    int Eclipse();
    bool isKnockedOut() const;

    /**
     * Gets the description of the player
     *
     * @return - description of the player
    */
    string getDescription() const;

    /**
     * Gets the name of the player
     *
     * @return - name of the player
    */
    string getName() const;

    /**
     * Gets the current level of the player
     *
     * @return - level of the player
    */
    int getLevel() const;

    /**
     * Gets the of force the player has
     *
     * @return - force points of the player
    */
    int getForce() const;

    /**
     * Gets the amount of health points the player currently has
     *
     * @return - health points of the player
    */
    int getHealthPoints() const;

    /**
     * Gets the amount of coins the player has
     *
     * @return - coins of the player
    */
    int getCoins() const;
};
