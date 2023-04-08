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
#include <algorithm>
#include <random>
#include "Types.h"
#include "Player.h"

Game::Game() {};

void Game::newGame() {
    printf(TITLE_TEXT);
    CardCollection deck = createDeck();
    initialisePlayers(deck);
    // Output player hands
    for (int i = 0; i < 2; i++) {
        printf("%s's Hand:\n", players[i].getName().c_str());
        CardCollection h = players[i].getHand();
        for (Card* card : h) {
            std::cout << card->str() << std::endl;
        }
    }

}
void Game::endGame() {

}
std::vector<Card*> Game::createDeck() {

    CardCollection deck;

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
    //shuffle the deck
    std::vector<Card*> shuffleDeck{ deck.begin(), deck.end() };
    std::shuffle(shuffleDeck.begin(), shuffleDeck.end(), std::mt19937{ std::random_device{}() });
    deck = CardCollection{ shuffleDeck.begin(), shuffleDeck.end() };
    return deck;
}

void Game::initialisePlayers(CardCollection deck) {
    CardCollection hand1;
    CardCollection hand2;

    for (int i = 0; i < 10; i++) {
        hand1.push_back(deck.front());
        deck.erase(deck.begin());

    }
    for (int i = 0; i < 10; i++) {
        hand2.push_back(deck.front());
        deck.erase(deck.begin());

    }
    players[0] = Player(hand1);
    players[1] = Player(hand2);
    
}


//void turn();
//void swapHands();