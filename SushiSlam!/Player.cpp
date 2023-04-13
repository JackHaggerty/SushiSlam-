#include "Player.h"
#include "Types.h"

Player::Player() : name(""), hand(CardCollection()), tableau(CardCollection()) {
	std::string names[10] = { "Sam", "Billy", "Jen", "Bob", "Sally", "Joe", "Sue", "Sasha", "Tina", "Marge" };
	name = names[rand() % 10];
}

void Player::addToTableau(int num, CardCollection& h, CardCollection& t) const
{
	t.push_back(h[num - 1]);
	h.erase(h.begin() + num - 1);
}

void Player::returnTableau(CardCollection& t)
{
	for (int i = 0; i < t.size(); i++) {
		printf("%s\n", t[i]->str().c_str());
	}
}

int Player::calcScore(CardCollection& t)
{
	int tempuraCount = 0;
	int sashimiCount = 0;
	int dumplingCount = 0;
	int makiCount = 0;
	int egg = 0;
	int salmon = 0;
	int squid = 0;

	for (int i = 0; i < 10; i++) {
		if (t[i]->str() == "Tempura") {
			tempuraCount++;
		}
		else if (t[i]->str() == "Sashimi") {
			sashimiCount++;
		}
		else if (t[i]->str() == "Dumpling") {
			dumplingCount++;
		}

		else if (t[i]->str() == "Nigiri (Egg)") {
			egg++;
		}
		else if (t[i]->str() == "Nigiri (Squid)") {
			squid++;
		}
		else if (t[i]->str() == "Nigiri (Salmon)") {
			salmon++;
		}
	}

	int score = 0;
	// 5 points for every set of 2 Tempura cards
	score += (tempuraCount / 2) * 5;
	// 10 points for every set of 3 Sashmimi cards
	score += (sashimiCount / 3) * 10;
	// 1 point for egg
	score += egg;
	// 2 points for salmon
	score += salmon * 2;
	// 3 points for squid
	score += squid * 3;
	// dumplings
	if (dumplingCount > 4) {
			score += 15;
	}
	else if (dumplingCount == 4) {
		score += 10;
	}
	else if (dumplingCount == 3) {
		score += 6;
	}
	else if (dumplingCount == 2) {
		score += 3;
	}
	else if (dumplingCount == 1) {
		score += 1;
	}
	totalScore += score;

	return score;
}

int Player::makiCount(CardCollection& t)
{
	int makiCount = 0;
	for (int i = 0; i < 10; i++) {
		if (t[i]->str() == "MakiRoll (1)") {
			makiCount++;
		}
		else if (t[i]->str() == "MakiRoll (2)") {
			makiCount += 2;
		}
		else if (t[i]->str() == "MakiRoll (3)") {
			makiCount += 3;
		}
	}

	return makiCount;
}

void Player::clearTableau()
{
	tableau.clear();
}

std::string& Player::getName()
{
	return name;
}

CardCollection& Player::getHand()
{
	return hand;
}
CardCollection& Player::getTableau() {
	return tableau;
}

int Player::getTotalScore()
{
	return totalScore;
}
