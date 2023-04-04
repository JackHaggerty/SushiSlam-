#include <iostream>
#include <string>
class Game {
public:
    void newGame(){

        printf(TITLE_TEXT);
        

    };
    void endGame() {
    };
    void createDeck() {
    };
    void shuffle() {
    };
    void deal() {
    };
    void initialisePlayers() {
    };
    void turn() {
    };
    void swapHands() {
    };

private:
    int numPlayers_;
    int currentRound_; 
    int currentTurn_; 
    const char* TITLE_TEXT =
        "|       |  | |  |       |  | |  |   |       |   |   |   _   |  |_|  |  |\n"
        "|  _____|  | |  |  _____|  |_|  |   |  _____|   |   |  |_|  |       |  |\n"
        "| |_____|  |_|  | |_____|       |   | |_____|   |   |       |       |  |\n"
        "|_____  |       |_____  |       |   |_____  |   |___|       |       |__|\n"
        " _____| |       |_____| |   _   |   |_____| |       |   _   | ||_|| |__\n"
        "|_______|_______|_______|__| |__|___|_______|_______|__| |__|_|   |_|__|\n";

};
class Player {

};
class Card {
public:
    enum CardType { MakiRoll_1, MakiRoll_2, MakiRoll_3, Tempura_card, Dumpling_card, Nigiri_egg, Nigiri_squid, Nigiri_salmon, Sashimi_card};
    virtual CardType Type() const = 0;
    virtual std::string str() const = 0;
};


class MakiRoll : public Card {
public:
    MakiRoll(int numRolls) : m_numRolls(numRolls) {
        switch (numRolls) {
            // valid entries, once match is made, break
            case 1: m_type = MakiRoll_1; break;
            case 2: m_type = MakiRoll_2; break;
            case 3: m_type = MakiRoll_3; break;
        }
    }
    virtual CardType Type() const override { 
        return m_type; 
    }
    // tostring
    virtual std::string str() const override { 
        return "MakiRoll (" + std::to_string(m_numRolls) + ")"; 
    }
private:
    CardType m_type;
    int m_numRolls;
};

class Nigiri : public Card {
public:
    Nigiri(const std::string& protein) : m_protein(protein) {
        if (protein == "Salmon") {
            m_type = Nigiri_salmon;
        }
        else if (protein == "Egg") {
            m_type = Nigiri_egg;
        }
        else if (protein == "Squid") {
            m_type = Nigiri_squid;
        }
    }
    virtual CardType Type() const override {
        return m_type;
    }
    virtual std::string str() const override {
        return "Nigiri ("+m_protein+")";
    }
private:
    CardType m_type;
    std::string m_protein;
};

class Sashimi : public Card {
public:
    virtual CardType Type() const override {
        return m_type;
    }
    virtual std::string str() const override {
        return "Sashimi";
    }
private:
    CardType m_type = Sashimi_card;
};

class Dumpling : public Card {
public:
    virtual CardType Type() const override {
        return m_type;
    }
    virtual std::string str() const override {
        return "Dumpling";
    }
private:
    CardType m_type = Dumpling_card;
};

class Tempura : public Card {
public:
    virtual CardType Type() const override {
        return m_type;
    }
    virtual std::string str() const override {
        return "Tempura";
    }
private:
    CardType m_type = Tempura_card;
};



int main()
{
    Game game;
    game.newGame();

    return 0;

    

}

