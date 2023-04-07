#pragma once
#include "Card.h"
class Dumpling : public Card
{
public:
    Dumpling() {
        m_type = Card::Dumpling_card;
    }
    virtual CardType Type() const override;
    virtual std::string str() const override;
private:
    CardType m_type;
};

