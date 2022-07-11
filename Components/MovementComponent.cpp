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

const float& MovementComponent::getMaxVelocity() const
{
    return this->maxVelocity;
}

const bool MovementComponent::getMovingState(const short unsigned state){
    switch(state){
    case IDLE:
        return this->velocity.x == 0.f && this->velocity.y == 0.f;
        break;
    case MOVING:
        return getMovingState(MOVING_LEFT) || getMovingState(MOVING_RIGHT) || getMovingState(MOVING_UP)|| getMovingState(MOVING_DOWN);
    case MOVING_LEFT:
        return this->velocity.x < 0.f;
    case MOVING_RIGHT:
        return this->velocity.x > 0.f;
    case MOVING_UP:
        return this->velocity.y < 0.f;
    case MOVING_DOWN:
        return this->velocity.y > 0.f;
    case SPRINT:
        return getMovingState(SPRINT_LEFT) || getMovingState(SPRINT_RIGHT) || getMovingState(SPRINT_UP)|| getMovingState(SPRINT_DOWN);
    case SPRINT_RIGHT:
        return this->velocity.x > this->maxVelocity * 95/100;
    case SPRINT_LEFT:
        return this->velocity.x < -this->maxVelocity * 95/100;
    case SPRINT_UP:
        return this->velocity.y < -this->maxVelocity * 95/100;
    case SPRINT_DOWN:
        return this->velocity.y > this->maxVelocity * 95/100;
    }
    return false;
}

void MovementComponent::setMaxVelocity(float newMaxVelocity){
    this->maxVelocity = newMaxVelocity >= 0 ? newMaxVelocity : 0;
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
