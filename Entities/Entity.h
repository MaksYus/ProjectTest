#ifndef ENTITY_H
#define ENTITY_H

#include<MovementComponent.h>

class Entity
{
    public:
        Entity();
        virtual ~Entity();


        void createSprite(sf::Texture* texture);
        void createMovementComponent(const float maxVelocity);

        virtual void update(const float& dt );
        virtual void render(sf::RenderTarget* target);

        virtual void setPosition(const float x, const float y);
        virtual void move(const float& dt, const float x, const float y);
    protected:
        sf::Sprite* sprite;
        sf::Texture* texture;
        MovementComponent* movementComponent;

    private:
        void initVariables();
};

#endif // ENTITY_H
