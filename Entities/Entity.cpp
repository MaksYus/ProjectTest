#include "Entity.h"

Entity::Entity()
{
    this->initVariables();
}

Entity::~Entity()
{
    delete this->sprite;
}

void Entity::update(const float& dt){

}

void Entity::render(sf::RenderTarget* target){
    if(this->sprite)
        target->draw(*this->sprite);
}

void Entity::initVariables(){
    this->sprite = NULL;
    this->texture = NULL;
    this->movementComponent = NULL;
}

void Entity::createSprite(sf::Texture* texture){
    this->texture = texture;
    this->sprite = new sf::Sprite(*this->texture);
}

void Entity::createMovementComponent(const float maxVelocity){
    this->movementComponent = new MovementComponent(maxVelocity);
}

void Entity::setPosition(const float x, const float y){
     if(this->sprite){
           this->sprite->setPosition(x, y);
    }
}

void Entity::move(const float& dt, const float dir_x, const float dir_y){
    if(this->sprite && this->movementComponent){
            this->movementComponent->move(dir_x,dir_y);
           this->sprite->move(this->movementComponent->getVelocity() * dt);
    }
}



