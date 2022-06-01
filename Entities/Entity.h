#ifndef ENTITY_H
#define ENTITY_H

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<stack>
#include<map>
#include<fstream>
#include<sstream>

#include"SFML/System.hpp"
#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
#include"SFML/Audio.hpp"
#include"SFML/Network.hpp"

class Entity
{
    public:
        Entity();
        virtual ~Entity();


        void createSprite(sf::Texture* texture);
        virtual void update(const float& dt );
        virtual void render(sf::RenderTarget* target);

        virtual void setPosition(const float x, const float y);
        virtual void move(const float& dt, const float x, const float y);
    protected:
        sf::Sprite* sprite;
        float movementSpeed;
        sf::Texture* texture;

    private:
        void initVariables();
};

#endif // ENTITY_H
