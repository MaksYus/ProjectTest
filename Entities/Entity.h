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
        Entity(sf::Vector2f Size = sf::Vector2f(50.f,50.f), sf::Color Color = sf::Color::White, sf::Vector2f Position = sf::Vector2f(0.f,0.f), float MovementSpeed = 700.f);
        virtual ~Entity();

        virtual void update(const float& dt );
        virtual void render(sf::RenderTarget* target);

        virtual void move(const float& dt, const float x, const float y);
    protected:
        sf::RectangleShape shape;
        float movementSpeed;

    private:
};

#endif // ENTITY_H
