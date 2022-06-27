#ifndef ANIMATIONCOMPONENT_H
#define ANIMATIONCOMPONENT_H

#include<iostream>
#include<map>
#include<fstream>
#include<sstream>

#include"SFML/System.hpp"
#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
#include"SFML/Audio.hpp"
#include"SFML/Network.hpp"


class AnimationComponent
{
    public:

        AnimationComponent(sf::Sprite& sprite, sf::Texture& texture_sheet);
        virtual ~AnimationComponent();

        void addAnimation(const std::string key,
                          float animationTimer,
                          int start_x, int start_y, int end_x, int end_y, int width, int height);

        void play(const std::string key, const float& dt);

    protected:

    private:
        class Animation{
        public:
            sf::Sprite& sprite;
            sf::Texture& textureSheet;
            float animationTimer;
            float timer;
            int width;
            int height;
            sf::IntRect startRect;
            sf::IntRect currentRect;
            sf::IntRect endRect;

            Animation(sf::Sprite& sprite, sf::Texture& textureSheet,
                      float animationTimer,
                      int start_x, int start_y, int end_x, int end_y, int width, int height):
                sprite(sprite), textureSheet(textureSheet), animationTimer(animationTimer), width(width), height(height)
            {
                this->startRect = sf::IntRect(start_x* width, start_y * height, width, height);
                this->endRect = sf::IntRect(end_x * width, end_y * height, width, height);

                this->sprite.setTexture(this->textureSheet,true);
                this->currentRect = this->startRect;
                this->sprite.setTextureRect(this->startRect);
            }

            void play(const float& dt){
                this->timer = 10.f * dt;
                if (this->timer >= this->animationTimer){
                    this->timer = 0.f;

                    if (this->currentRect != this->endRect){
                        this->currentRect.left += this->width;
                    }
                    else{
                        this->currentRect.left = this->startRect.left;
                    }

                    this->sprite.setTextureRect(this->currentRect);
                }
            }

            void reset(){
                this->timer = 0.f;
                this->currentRect = this->startRect;
            }
        };

        sf::Sprite& sprite;
        sf::Texture& textureSheet;
        std::map<std::string, Animation*> animations;
        std::map<std::string, Animation*>::iterator it_animations = animations.begin();
};

#endif // ANIMATIONCOMPONENT_H
