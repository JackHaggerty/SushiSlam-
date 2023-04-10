#include "Player.h"
#include "Types.h"

Player::Player() : name(name), hand(CardCollection()), tableau(CardCollection()) {}

void Player::addToTableau() const
{
}

void Player::calcScore()
{
}

void Player::clearTableau()
{
}

std::string Player::getName()
{
	return name;
}

CardCollection& Player::getHand()
{
	return hand;
}
CardCollection Player::getTableau() {
	return tableau;
}