#include "Game.h"
#include <iostream>
#include <string>
#include <vector>
#include "Card.h"
#include "Game.h"
#include "MakiRoll.h"
#include "Nigiri.h"
#include "Tempura.h"
#include "Dumpling.h"
#include "Sashimi.h"

Game::Game() {
    numPlayers_;
    currentRound_;
    currentTurn_;
    TITLE_TEXT =
        "|       |  | |  |       |  | |  |   |       |   |   |   _   |  |_|  |  |\n"
        "|  _____|  | |  |  _____|  |_|  |   |  _____|   |   |  |_|  |       |  |\n"
        "| |_____|  |_|  | |_____|       |   | |_____|   |   |       |       |  |\n"
        "|_____  |       |_____  |       |   |_____  |   |___|       |       |__|\n"
        " _____| |       |_____| |   _   |   |_____| |       |   _   | ||_|| |__\n"
        "|_______|_______|_______|__| |__|___|_______|_______|__| |__|_|   |_|__|\n";
};
void Game::newGame() {
    printf(TITLE_TEXT);
    std::vector<Card*> deck = createDeck();
}
void Game::endGame() {

}
std::vector<Card*> Game::createDeck() {
    std::vector<Card*> deck;

    for (int i = 0; i < 14;i++) {
        deck.push_back(new Tempura());
        deck.push_back(new Dumpling());
        deck.push_back(new Sashimi());
    }
    for (int i = 0; i < 5;i++) {
        deck.push_back(new Nigiri("Egg"));
        deck.push_back(new Nigiri("Squid"));
        deck.push_back(new Nigiri("Salmon"));
        deck.push_back(new Nigiri("Salmon"));
    }
    for (int i = 0; i < 6; i++) {
        deck.push_back(new MakiRoll(1));
        deck.push_back(new MakiRoll(2));
        deck.push_back(new MakiRoll(2));
    }
    for (int i = 0; i < 8; i++) {
        deck.push_back(new MakiRoll(3));

    }

    return deck;
}
//void shuffle();
//void deal();
//void initialisePlayers();
//void turn();
//void swapHands();