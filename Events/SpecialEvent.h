//
// Created by moham on 25/01/2025.
//
#pragma once

#ifndef MATAM4HW4_SPECIALEVENT_H
#define MATAM4HW4_SPECIALEVENT_H

#include "Event.h"
#include "../Utilities.h"

class SpecialEvent:public Event{

public:
    SpecialEvent()=default;
    virtual ~SpecialEvent()=default;

    virtual string getDescription() const override=0;

    virtual void EncounterEvent(std::shared_ptr<Player> player) override =0;
};

class SolarEclipse:public SpecialEvent{

public:
    SolarEclipse():SpecialEvent(){}
    virtual ~SolarEclipse()=default;

    string getDescription() const override;

    void EncounterEvent(std::shared_ptr<Player> player) override;

};

class PotionsMerchant:public SpecialEvent{
    int m_cost, m_HealingPoints;
public:
    PotionsMerchant(): SpecialEvent(), m_cost(5), m_HealingPoints(10){}
    virtual ~PotionsMerchant()=default;

    string getDescription() const override;

    void EncounterEvent(std::shared_ptr<Player> player) override;
};

#endif //HW4_MATAM_SPECIALEVENT_H
