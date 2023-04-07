#pragma once
#include "Card.h"

class Nigiri : public Card {
public:
    Nigiri(const std::string& protein);

    virtual CardType Type() const override;
    virtual std::string str() const override;

private:
    CardType m_type;
    std::string m_protein;
};

