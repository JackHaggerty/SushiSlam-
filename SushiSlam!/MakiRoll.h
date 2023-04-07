#ifndef MAKIROLL_H
#define MAKIROLL_H
#pragma once
#include "Card.h"

class MakiRoll : public Card {
public:
    MakiRoll(int numRolls);
    virtual CardType Type() const override;
    virtual std::string str() const override;
private:
    CardType m_type;
    int m_numRolls;
};

#endif