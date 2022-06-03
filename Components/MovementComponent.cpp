#include "MovementComponent.h"

MovementComponent::MovementComponent(float maxVelocity)
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

void MovementComponent::move(const float x, const float y){
    this->velocity.x = this->maxVelocity * x;
    this->velocity.y = this->maxVelocity * y;
}

void MovementComponent::update(const float& dt){

}
