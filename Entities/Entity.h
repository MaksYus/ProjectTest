#ifndef ENTITY_H
#define ENTITY_H

#include<MovementComponent.h>

class Entity
{
    public:
        Entity();
        virtual ~Entity();


        void setTexture(sf::Texture& texture);
        void createMovementComponent(const float maxVelocity,  const float acceleration, const float decceleration);

        virtual void update(const float& dt );
        virtual void render(sf::RenderTarget* target);

        virtual void setPosition(const float x, const float y);
        virtual void move(const float x, const float y, const float& dt);
    protected:
        sf::Sprite sprite;
        MovementComponent* movementComponent;

    private:
        void initVariables();
};

#endif // ENTITY_H
