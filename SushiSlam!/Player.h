#pragma once
#include <string>
#include "Types.h"
class Player
{
public:
	Player();

	void addToTableau() const;
	void calcScore();
	void clearTableau();
	std::string getName();
	CardCollection& getHand();
	CardCollection getTableau();
private:
	std::string names[10] = { "Sam", "Billy", "Jen", "Bob", "Sally", "Joe", "Sue", "Sasha", "Tina", "Marge" }; ;
	int totalScore;
	std::string name = names[rand() % 10];
	CardCollection hand;
	CardCollection tableau;
};

