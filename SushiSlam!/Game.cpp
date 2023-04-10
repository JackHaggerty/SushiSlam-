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
    currentRound = 1;
    CardCollection deck = createDeck();
    initialisePlayers();
    Player p1 = players[0];
    Player p2 = players[1];

    printf(TITLE_TEXT);
    // round loop 
    while (currentRound < 4) {
        // round count
        printf("\n~~~ round %d/3 ~~~\n", currentRound);

        // from the deck, deal 10 cards to each player at beginning of each round
        deal(deck, p1, p2);
        // Print hand size for debugging
        std::cout << "Hand size: " << players[0].getHand().size() << std::endl;

        // loop
        while (p1.getHand().size() > 0 && p2.getHand().size() > 0) {
            for (int i = 0; i < 2; i++) {
                //current players turn
                currentTurn = players[i];
                CardCollection t = currentTurn.getTableau();
                CardCollection h = currentTurn.getHand();

                printf("\nPLAYER %s TURN\n", currentTurn.getName().c_str());
                printf("Tableau:\n");
                for (int i = 0; i < t.size(); i++) {
                    printf("%s\n", t[i]->str().c_str());
                }
                printf("Current hand:\n");
                for (int i = 0; i < h.size(); i++) {
                    printf("%d. %s\n",i + 1, h[i]->str().c_str());
                }


                int num;
                std::cout << "Select a card to add to your tableau: ";
                std::cin >> num;
                t.push_back(h[num - 1]);
                h.erase(h.begin() + num - 1);


            }
        }

        currentRound++;
    }


    

    // Output player hands
    //for (int i = 0; i < 2; i++) {
    //    CardCollection t = players[i].getTableau();
    //    CardCollection h = players[i].getHand();


    //    printf("PLAYER %s TURN\n", players[i].getName().c_str());
    //    printf("%s's Hand:\n", players[i].getName().c_str());
    //    printf("Tableau:\n");
    //    for (int i = 0; i < t.size(); i++) {
    //        printf("%d\n", t[i]->str().c_str());
    //    }
    //    for (int i = 0; i < h.size(); i++) {
    //        printf("%d. %s\n", i + 1, h[i]->str().c_str());
    //    }
    //    int num;
    //    std::cout << "Select a card to add to your tableau: ";
    //    std::cin >> num;
    //    t.push_back(h[num - 1]);
    //    h.erase(h[num - 1]);

 
    //}
    

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

void Game::initialisePlayers() {

    players[0] = Player();
    players[1] = Player();
    
}

void Game::deal(CardCollection& deck, Player& p1, Player& p2)
{
    std::cout << "Deck: ";
    for (int i = 0; i < deck.size(); i++) {
        std::cout << deck[i]->str() << " ";
    }
    std::cout << std::endl;


    //deals card to players
    for (int i = 0; i < 10; i++) {
        // player 1 hand
        p1.getHand().push_back(deck.front());
        deck.erase(deck.begin());
        // player 2 hand
        p2.getHand().push_back(deck.front());
        deck.erase(deck.begin());
    }
    // Print player hands for debugging
    std::cout << "Player 1 Hand: ";
    CardCollection h1 = p1.getHand();
    for (int i = 0; i < h1.size(); i++) {
        std::cout << h1[i]->str() << " ";
    }
    std::cout << std::endl;

    std::cout << "Player 2 Hand: ";
    CardCollection h2 = p2.getHand();
    for (int i = 0; i < h2.size(); i++) {
        std::cout << h2[i]->str() << " ";
    }
    std::cout << std::endl;
}


//void turn();
//void swapHands();