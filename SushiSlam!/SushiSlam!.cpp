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
    enum CardType { MakiRoll_1, MakiRoll_2, MakiRoll_3, Tempura, Dumpling, Nigiri_egg, Nigiri_squid, Nigiri_salmon, Sashimi};
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





int main()
{
    Game game;
    game.newGame();

    //test
    MakiRoll m(2);
    std::cout << m.str() << std::endl;
    return 0;
}

