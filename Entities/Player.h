#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"

class Player:
    public Entity
{
    public:
        Player(float x, float y, sf::Texture& texture_sheet);
        virtual ~Player();

    protected:

    private:
        void initVariables();
        void initComponents();
};

#endif // PLAYER_H
