#pragma once
#include <vector>
#include "Card.h"

class Game {
public:
    Game();
    void newGame();
    void endGame();
    std::vector<Card*> createDeck();           
    void shuffle();
    void deal();
    void initialisePlayers();
    void turn();
    void swapHands();

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


