#include "HitboxComponent.h"

HitboxComponent::HitboxComponent(sf::Sprite& sprite, float x, float y, float width, float height)
    :sprite(sprite), X(x), Y(y)
{
    this->hitbox.setPosition(this->sprite.getPosition().x + x, this->sprite.getPosition().y + y);
    this->hitbox.setSize(sf::Vector2f(width,height));
    this->hitbox.setFillColor(sf::Color::Transparent);
    this->hitbox.setOutlineThickness(1.f);
    this->hitbox.setOutlineColor(sf::Color::Green);
}

HitboxComponent::~HitboxComponent()
{
    //dtor
}

bool HitboxComponent::checkIntersect(const sf::FloatRect& frect){

    return this->hitbox.getGlobalBounds().intersects(frect);
}

void HitboxComponent::update(){
    this->hitbox.setPosition(this->sprite.getPosition().x + this->X, this->sprite.getPosition().y + this->Y);
}

void HitboxComponent::render(sf::RenderTarget& target){
    target.draw(this->hitbox);
}
