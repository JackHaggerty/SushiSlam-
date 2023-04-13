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
    Player* p1 = players[0];
    Player* p2 = players[1];

    // sushi slam title
    printf(TITLE_TEXT);
    // round loop 
    while (currentRound < 4) {
        // round count
        printf("\n~~~ round %d/3 ~~~\n", currentRound);

        // from the deck, deal 10 cards to each player at beginning of each round
        deal(deck, p1, p2);


        // loop for current round, swapping hands and choosing cards
        while (p1->getHand().size() > 0 && p2->getHand().size() > 0) {
            // for loop to swap from player to player
            for (int i = 0; i < 2; i++) {
                //current players turn
                Player * currentPlayer = players[i];
                // current players tableau
                CardCollection& t = currentPlayer->getTableau();
                // current players hand
                CardCollection& h = currentPlayer->getHand();
                
                printf("\nPLAYER %s TURN\n", currentPlayer->getName().c_str());
                printf("Tableau:\n");

                // return tableau 
                currentPlayer->returnTableau(t);
                // return current players hand
                printf("Current hand:\n");
                for (int i = 0; i < h.size(); i++) {
                    printf("%d. %s\n",i + 1, h[i]->str().c_str());
                }

                // prompt user to choose a chard to add to their tableau
                int num;
                std::cout << "Select a card to add to your tableau: ";
                std::cin >> num;
                // remove cards from hand and place into the tableau
                currentPlayer->addToTableau(num, h, t);
            }
            // swap hands after each player has placed a card into their tableau
            swapHands(p1, p2);
        }
        // calculate scores
        int p1Score = p1->calcScore(p1->getTableau());
        int p2Score = p2->calcScore(p2->getTableau());
        // count maki rolls
        int p1MakiCount = p1->makiCount(p1->getTableau());
        int p2MakiCount = p2->makiCount(p2->getTableau());

        if (p1MakiCount > p2MakiCount) {
            p1Score += 6;
            p2Score += 3;
        }
        else if (p2MakiCount > p1MakiCount) {
            p2Score += 6;
            p1Score += 3;
        }
        else if (p2MakiCount == p1MakiCount) {
            p2Score += 3;
            p1Score += 3;
        }

        printf("\n~~~ end of round scoring ~~~\n");
        printf("    PLAYER %s round score: %d\n", p1->getName().c_str(), p1Score);
        printf("    PLAYER %s round score: %d\n", p2->getName().c_str(), p2Score);

        // clear tableaus
        p1->clearTableau();
        p2->clearTableau();
        

        currentRound++;
    }
    // game end
    printf("\n~~~ End of game! ~~~\n");
    // final scores for the 3 rounds played
    printf("    PLAYER %s final score: %d\n", p1->getName().c_str(), p1->getTotalScore());
    printf("    PLAYER %s final score: %d\n", p2->getName().c_str(), p2->getTotalScore());
    // calculate winner
    if (p1->getTotalScore() > p2->getTotalScore()) {
        printf("PLAYER %s WINS!", p1->getName().c_str());
    }
    else if (p2->getTotalScore() > p1->getTotalScore()) {
        printf("PLAYER %s WINS!", p2->getName().c_str());
    }
    else {
        printf("SCORES EVEN, ITS A TIE!");
    }
    // end game clean up memory
    endGame(deck);
}
void Game::endGame(CardCollection& deck) {
     //clean up memory 
    // players
    for (int i = 0; i < 2; i++) {
        delete players[i];
    }
    delete[] players;

    // deck
    for (int i = 0; i < deck.size(); i++) {
        delete deck[i];
    }
    deck.clear();


}
std::vector<Card*> Game::createDeck() {

    CardCollection deck;
    // 14 Tempura, Dumping, Sashimi cards
    for (int i = 0; i < 14;i++) {
        deck.push_back(new Tempura());
        deck.push_back(new Dumpling());
        deck.push_back(new Sashimi());
    }
    // 5 egg, squid cards and 10 salmon
    for (int i = 0; i < 5;i++) {
        deck.push_back(new Nigiri("Egg"));
        deck.push_back(new Nigiri("Squid"));
        deck.push_back(new Nigiri("Salmon"));
        deck.push_back(new Nigiri("Salmon"));
    }
    // 6 Makiroll (1), 12 Makiroll (2)
    for (int i = 0; i < 6; i++) {
        deck.push_back(new MakiRoll(1));
        deck.push_back(new MakiRoll(2));
        deck.push_back(new MakiRoll(2));
    }
    // 8 Makiroll (3)
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

    players[0] = new Player();
    players[1] = new Player();
    
}

void Game::deal(CardCollection& deck, Player* p1, Player* p2)
{
    //deals card to players
    for (int i = 0; i < 10; i++) {
        // player 1 hand
        p1->getHand().push_back(deck.front());
        deck.erase(deck.begin());
        // player 2 hand
        p2->getHand().push_back(deck.front());
        deck.erase(deck.begin());
    }

}

void Game::swapHands(Player* p1, Player* p2)
{
    std::swap(p1->getHand(), p2->getHand());
}