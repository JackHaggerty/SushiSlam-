#pragma once
#include <string>
#include "Types.h"
class Player
{
public:
	Player();
	Player(CardCollection hand);
	void addToTableau() const;
	void calcScore();
	void clearTableau();
	void tableau();
	std::string getName();
	CardCollection getHand();
private:
	std::string names[10] = { "Sam", "Billy", "Jen", "Bob", "Sally", "Joe", "Sue", "Sasha", "Tina", "Marge" }; ;
	int totalScore;
	std::string name = names[rand() % 10];
	CardCollection hand;
};

