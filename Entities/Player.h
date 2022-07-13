#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player:
    public Entity
{
    public:
        Player(float x, float y,std::map<std::string, sf::Texture> texture_sheets);
        virtual ~Player();

        virtual void update(const float&dt);
        virtual void updateAnimation(const float & dt);
        virtual void interact(Entity& sender);

        virtual std::string getInfo();
    protected:

    private:
        void initVariables();
        void initComponents();
        void initAnimations();

        bool animationCut;

        std::map<std::string, sf::Texture>  textureSheets;

        std::vector<std::string> cutAnim;
        std::vector<std::string> idleAnim;
        std::vector<std::string> bacwalkAnim;
        std::vector<std::string> sprintAnim;
        std::vector<std::string> walkAnim;
};

#endif // PLAYER_H
