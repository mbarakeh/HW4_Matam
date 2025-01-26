#pragma once

#include "../Players/Player.h"
#include <memory>

class Event {
public:
    /**
     * Gets the description of the event
     *
     * @return - the description of the event
    */
    virtual string getDescription() const=0;

    Event()=default;
    virtual ~Event()=default;
    virtual void EncounterEvent(std::shared_ptr<Player> player)=0;
};