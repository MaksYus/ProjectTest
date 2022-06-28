#include "MovementComponent.h"

MovementComponent::MovementComponent( sf::Sprite& sprite, float maxVelocity, float acceleration, float decceleration)
: sprite(sprite), maxVelocity(maxVelocity) , acceleration(acceleration), decceleration(decceleration)
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

const bool MovementComponent::idle() const{
    return this->velocity.x == 0.f && this->velocity.y == 0.f;
}

void MovementComponent::move(const float x, const float y,const float& dt){
    this->velocity.x += this->acceleration * x;
    this->velocity.y += this->acceleration * y;
}

void MovementComponent::update(const float& dt){
    if(this->velocity.x > 0.f){
        if (this->velocity.x > this->maxVelocity)
            this->velocity.x = this->maxVelocity;

        this->velocity.x -= decceleration;
        if(this->velocity.x < 0.f)
            this->velocity.x = 0.f;
    }
    else if(this->velocity.x <0.f){
        if(this->velocity.x < -this->maxVelocity)
                this->velocity.x = -this->maxVelocity;

        this->velocity.x += decceleration;
        if(this->velocity.x > 0.f)
            this->velocity.x = 0.f;
    }

    if(this->velocity.y > 0.f){
        if(this->velocity.y > this->maxVelocity)
            this->velocity.y = this->maxVelocity;

        this->velocity.y -= decceleration;
        if(this->velocity.y < 0.f)
            this->velocity.y = 0.f;
    }
    else if(this->velocity.y <0.f){
        if(this->velocity.y < -this->maxVelocity)
           this->velocity.y = -this->maxVelocity;

        this->velocity.y += decceleration;
        if(this->velocity.y > 0.f)
            this->velocity.y = 0.f;
    }

    this->sprite.move(this->velocity*dt);
}
