#include "Player.h"

Player::Player(float x, float y, sf::Texture& texture_sheet)
{
    this->initVariables();

    this->setTexture(texture_sheet);
    this->setPosition(x, y);

    this->createMovementComponent(700.f, 100.f, 10.f);
    this->createAnimationComponent(this->sprite,texture_sheet);

   // this->animationComponent->addAnimation("IDLE_LEFT",100.f,1,1, кол-во анимаций,,)
}

Player::~Player()
{
    //dtor
}

void Player::initVariables(){

}

void Player::initComponents(){

}
