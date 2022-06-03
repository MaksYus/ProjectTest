#ifndef MOVEMENTCOMPONENT_H
#define MOVEMENTCOMPONENT_H

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

class MovementComponent
{
    public:
        MovementComponent(float maxVelocity);
        virtual ~MovementComponent();

        const sf::Vector2f& getVelocity() const;

        void move(const float x, const float y);
        void update(const float& dt);
    protected:

    private:
        float maxVelocity;
        sf::Vector2f velocity;
        sf::Vector2f acceleration;
        sf::Vector2f deceleration;


};

#endif // MOVEMENTCOMPONENT_H
