#include "Player.h"

Player::Player(float x, float y, sf::Texture& texture)
{
    this->initVariables();
    this->initComponents();

    this->setTexture(texture);
    this->setPosition(x, y);
}

Player::~Player()
{
    //dtor
}

void Player::initVariables(){

}

void Player::initComponents(){
    this->createMovementComponent(700.f, 100.f, 10.f);
}
