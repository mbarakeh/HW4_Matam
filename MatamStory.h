
#pragma once

#include <iostream>
#include "Events/Event.h"
#include "Events/SpecialEvent.h"
#include "Events/Encounter.h"
#include <vector>
#include <memory>
#include "Utilities.h"

using std::vector;

class MatamStory{
private:
    vector<std::shared_ptr<Event>> m_Events;
    vector<std::shared_ptr<Player>> m_AllPlayers;
    vector<std::shared_ptr<Player>> m_AlivePlayers;

    std::shared_ptr<Player> m_CurrentPlayer;
    int m_numberOfPlayers;
    unsigned int m_turnIndex;

    /**
     * Playes a single turn for a player
     *
     * @param player - the player to play the turn for
     *
     * @return - void
    */
    void playTurn(Player& player);

    /**
     * Plays a single round of the game
     *
     * @return - void
    */
    void playRound();

    /**
     * Checks if the game is over
     *
     * @return - true if the game is over, false otherwise
    */
    bool isGameOver() const;

    void ReadEvents(std::istream& eventsStream);
    std::shared_ptr<Event> EventInventer(std::string& EventName, std::istream& eventsStream);
    std::shared_ptr<Monster> MonsterInventer(std::string& EventName, std::istream& eventsStream);

    void ReadPlayers(std::istream& playersStream);
    Job* CreateJob(std::string PlayerName,std::string& JobName);
    Character* CreateCharacter(std::string& CharacterName, Job* job);

    void printLeaderBoardByorder() const;

    vector<std::shared_ptr<Player>>::const_iterator getTopPlayer(const vector<std::shared_ptr<Player>>& copy) const;


public:
    /**
     * Constructor of MatamStory class
     *
     * @param eventsStream - events input stream (file)
     * @param playersStream - players input stream (file)
     *
     * @return - MatamStory object with the given events and players
     *
    */
    MatamStory(std::istream& eventsStream, std::istream& playersStream);

    /**
     * Plays the entire game
     *
     * @return - void
    */
    void play();
};
