#pragma once
#include "Card.h"
class Sashimi : public Card
{
public:
    virtual CardType Type() const override;
    virtual std::string str() const override;
private:
    CardType m_type;
};

