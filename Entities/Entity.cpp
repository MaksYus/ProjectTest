#include "Entity.h"

Entity::Entity(sf::Vector2f Size, sf::Color Color, sf::Vector2f Position, float MovementSpeed)
{
    this->shape.setSize(Size);
    this->shape.setFillColor(Color);
    this->shape.setPosition(Position);
    this->movementSpeed = MovementSpeed;
}

Entity::~Entity()
{
    //dtor
}

void Entity::update(const float& dt){

}

void Entity::render(sf::RenderTarget* target){
    target->draw(this->shape);
}

void Entity::move(const float& dt, const float dir_x, const float dir_y){
    this->shape.move(dir_x * this->movementSpeed * dt,dir_y * this->movementSpeed * dt);
}



