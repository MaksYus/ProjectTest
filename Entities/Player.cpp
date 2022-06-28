#include "Player.h"

Player::Player(float x, float y, sf::Texture& texture_sheet)
{
    this->initVariables();

    this->setPosition(x, y);

    this->createMovementComponent(700.f, 100.f, 10.f);
    this->createAnimationComponent(texture_sheet);

    this->animationComponent->addAnimation("IDLE_RIGHT",2.f,0,0, 8,0,64,64);
    this->animationComponent->addAnimation("WALK_RIGHT",2.f,0,0, 8,0,64,64);
}

Player::~Player()
{
    //dtor
}

void Player::initVariables(){

}

void Player::initComponents(){

}

void Player::update(const float&dt){
    this->movementComponent->update(dt);

    if (this->movementComponent->idle())
        this->animationComponent->play("IDLE_RIGHT", dt);
    else
        this->animationComponent->play("WALK_RIGHT", dt);
}
