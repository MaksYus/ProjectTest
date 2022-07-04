#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(sf::Sprite& sprite, sf::Texture& texture_sheet):
    sprite(sprite), textureSheet(texture_sheet)
{
    this->lastAnimation = NULL;
    //ctor
}

AnimationComponent::~AnimationComponent()
{
    this->it_animations = this->animations.begin();
    for (int i = 0; this->it_animations != this->animations.end(); this->it_animations++, i++)
        delete this->it_animations->second;
}

void AnimationComponent::addAnimation(const std::string key,
                                      float animationTimer,
                                      int start_x, int start_y, int end_x, int end_y, int width, int height){
    this->animations[key] = new Animation(this->sprite,this->textureSheet,
                                      animationTimer,
                                      start_x, start_y,end_x,end_y, width, height);
}

void AnimationComponent::play(const std::string key, const float& dt){
    //TODO тут вылетает ошибка, исправить
    if(this->lastAnimation != this->animations[key]){
        if(this->lastAnimation == NULL)
            this->lastAnimation = this->animations[key];
        else{
            this->lastAnimation->reset();
            this->lastAnimation = this->animations[key];
        }
    }
    this->animations[key]->play(dt);
}
