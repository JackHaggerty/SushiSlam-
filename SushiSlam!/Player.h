#pragma once
#include <string>
#include "Types.h"
class Player
{
public:
	Player();

	void addToTableau(int num, CardCollection& h, CardCollection& t) const;
	void returnTableau(CardCollection& t);
	int calcScore(CardCollection& t);
	int makiCount(CardCollection& t);
	void clearTableau();
	std::string& getName();
	CardCollection& getHand();
	CardCollection& getTableau();
	int getTotalScore();
private:

	int totalScore;
	std::string name;
	CardCollection hand;
	CardCollection tableau;
};

