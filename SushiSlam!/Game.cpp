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
    
    CardCollection deck = createDeck();
    initialisePlayers(deck);
    printf(TITLE_TEXT);
    printf("\n~~~ round 1/3 ~~~\n");
    int x = 0;
    while (x != 1) {
        // Output player hands
        for (int i = 0; i < 2; i++) {
            CardCollection t = players[i].getTableau();
            CardCollection h = players[i].getHand();


            printf("PLAYER %s TURN\n", players[i].getName().c_str());
            printf("%s's Hand:\n", players[i].getName().c_str());
            printf("Tableau:\n");
            for (int i = 0; i < t.size(); i++) {
                printf("%d\n", t[i]->str().c_str());
            }
            for (int i = 0; i < h.size(); i++) {
                printf("%d. %s\n", i + 1, h[i]->str().c_str());
            }
            int num;
            std::cout << "Select a card to add to your tableau: ";
            std::cin >> num;
            t.push_back(h[num - 1]);
            h.erase(h[num - 1]);

 
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