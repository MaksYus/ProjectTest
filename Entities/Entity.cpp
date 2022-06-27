#include "Entity.h"

Entity::Entity()
{
    this->initVariables();
}

Entity::~Entity()
{
    delete this->movementComponent;
    delete this->animationComponent;
}

void Entity::update(const float& dt){
    if(this->movementComponent){
        this->movementComponent->update(dt);
    }
}

void Entity::render(sf::RenderTarget* target){
        target->draw(this->sprite);
}

void Entity::initVariables(){
    this->movementComponent = NULL;
}

void Entity::setTexture(sf::Texture& texture){
    this->sprite.setTexture(texture);
}

void Entity::createMovementComponent(const float maxVelocity, const float acceleration, const float decceleration){
    this->movementComponent = new MovementComponent(this->sprite, maxVelocity, acceleration, decceleration);
}

void Entity::createAnimationComponent(sf::Sprite& sprite, sf::Texture& texture_sheet){
    this->animationComponent = new AnimationComponent(sprite,texture_sheet);
}

void Entity::setPosition(const float x, const float y){
           this->sprite.setPosition(x, y);
}

void Entity::move(const float dir_x, const float dir_y, const float& dt){
    if(this->movementComponent){
            this->movementComponent->move(dir_x,dir_y, dt);
    }
}



