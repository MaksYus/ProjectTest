#include "Player.h"

Player::Player(float x, float y, sf::Texture& texture_sheet)
{
    this->initVariables();

    this->setPosition(x, y);

    this->createMovementComponent(500.f, 20.f, 10.f);
    this->createAnimationComponent(texture_sheet);

    this->animationComponent->addAnimation("IDLE_RIGHT",2.f,0,0, 8,0,64,64);
    this->animationComponent->addAnimation("WALK_RIGHT",0.25,0,1, 5,1,64,64);
    this->animationComponent->addAnimation("IDLE_LEFT",2.f,0,2, 8,2,64,64);
    this->animationComponent->addAnimation("WALK_LEFT",0.25,0,3, 5,3,64,64);
    this->animationComponent->addAnimation("SPRINT_RIGHT",0.25,0,4,4,4,64,64);
    this->animationComponent->addAnimation("SPRINT_LEFT",0.25,0,5,4,5,64,64);
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

    sf::Vector2i mousePos = sf::Mouse::getPosition();
    if (this->movementComponent->getMovingState(IDLE)){
        if(this->sprite.getPosition().x + 32 < mousePos.x){
            this->animationComponent->play("IDLE_RIGHT", dt);}
        else{
            this->animationComponent->play("IDLE_LEFT", dt);}
        }
    else{
        if(this->movementComponent->getMovingState(SPRINT_LEFT) || this->movementComponent->getMovingState(SPRINT_RIGHT)){
            if(this->sprite.getPosition().x + 32 < mousePos.x)
            this->animationComponent->play("SPRINT_RIGHT", dt);
        else
            this->animationComponent->play("SPRINT_LEFT", dt);
        }
        else{
            if(this->sprite.getPosition().x + 32 < mousePos.x)
            this->animationComponent->play("WALK_RIGHT", dt);
        else
            this->animationComponent->play("WALK_LEFT", dt);
        }
        }
}
