#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player:
    public Entity
{
    public:
        Player(float x, float y, sf::Texture& texture_sheet);
        virtual ~Player();

        virtual void update(const float&dt);
    protected:

    private:
        void initVariables();
        void initComponents();
        void initAnimations();

        sf::Texture& textureSheet;
};

#endif // PLAYER_H
