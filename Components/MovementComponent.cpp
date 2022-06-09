#include "MovementComponent.h"

MovementComponent::MovementComponent( sf::Sprite& sprite, float maxVelocity)
: sprite(sprite), maxVelocity(maxVelocity)
{
    this->maxVelocity = maxVelocity;
}

MovementComponent::~MovementComponent()
{
    //dtor
}

const sf::Vector2f & MovementComponent::getVelocity() const{
    return this->velocity;
}

void MovementComponent::move(const float x, const float y,const float& dt){
    this->velocity.x = this->maxVelocity * x;
    this->velocity.y = this->maxVelocity * y;
    this->sprite.move(this->velocity*dt);
}

void MovementComponent::update(const float& dt){

}
