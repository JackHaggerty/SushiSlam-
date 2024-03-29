#pragma once
#include <vector>
#include "Card.h"
#include "Types.h"
#include "Player.h"
class Game {
public:
    Game();
    void newGame();
    void endGame(CardCollection& deck);
    CardCollection createDeck();
    void initialisePlayers();
    void deal(CardCollection& deck, Player* p1, Player* p2);
    void swapHands(Player* p1, Player* p2);

private:
    Player* players[2];
    int currentRound = 1;
    Player currentPlayer;
    const char* TITLE_TEXT =
        "|       |  | |  |       |  | |  |   |       |   |   |   _   |  |_|  |  |\n"
        "|  _____|  | |  |  _____|  |_|  |   |  _____|   |   |  |_|  |       |  |\n"
        "| |_____|  |_|  | |_____|       |   | |_____|   |   |       |       |  |\n"
        "|_____  |       |_____  |       |   |_____  |   |___|       |       |__|\n"
        " _____| |       |_____| |   _   |   |_____| |       |   _   | ||_|| |__\n"
        "|_______|_______|_______|__| |__|___|_______|_______|__| |__|_|   |_|__|\n";
};


