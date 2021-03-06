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

enum moving_states{IDLE = 0, MOVING, MOVING_LEFT, MOVING_RIGHT, MOVING_UP, MOVING_DOWN, SPRINT, SPRINT_LEFT, SPRINT_RIGHT, SPRINT_UP, SPRINT_DOWN};
enum looking_states{RIGHT = 0, LEFT, UP, DOWN};

class MovementComponent
{
    public:
        MovementComponent(sf::Sprite& sprite,
                           float maxVelocity,
                            float acceleration, float decceleration);
        virtual ~MovementComponent();

        const sf::Vector2f& getVelocity() const;
        const float& getMaxVelocity() const;
        const bool getMovingState(const short unsigned state);

        void setMaxVelocity(float newMaxVelocity);

        void move(const float x, const float y,const float& dt);
        void update(const float& dt);
    protected:

    private:
        sf::Sprite& sprite;
        float maxVelocity;
        sf::Vector2f velocity;
        float acceleration;
        float decceleration;


};

#endif // MOVEMENTCOMPONENT_H
