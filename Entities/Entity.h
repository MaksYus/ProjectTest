#ifndef ENTITY_H
#define ENTITY_H

#include<MovementComponent.h>
#include<AnimationComponent.h>
#include<HitboxComponent.h>

class Entity
{
    public:
        Entity();
        virtual ~Entity();

        void setTexture(sf::Texture& texture);
        void createHitboxComponent( sf::Sprite& Sprite, float x, float y, float width, float height);
        void createMovementComponent(const float maxVelocity,  const float acceleration, const float decceleration);
        void createAnimationComponent( sf::Texture& texture_sheet);

        virtual void update(const float& dt );
        virtual void render(sf::RenderTarget& target);

        virtual void setPosition(const float x, const float y);
        virtual void move(const float x, const float y, const float& dt);
    protected:
        sf::Sprite sprite;

        HitboxComponent* hitboxComponent;
        MovementComponent* movementComponent;
        AnimationComponent* animationComponent;

    private:
        void initVariables();
};

#endif // ENTITY_H
