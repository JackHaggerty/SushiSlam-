#pragma once
#include <string>

class Card {
public:
    Card();
    enum CardType { MakiRoll_1, MakiRoll_2, MakiRoll_3, Tempura_card, Dumpling_card, Nigiri_egg, Nigiri_squid, Nigiri_salmon, Sashimi_card };
    virtual CardType Type() const;
    virtual std::string str() const;
};
