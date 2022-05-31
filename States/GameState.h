#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "State.h"

class GameState : public State
{
    public:
        GameState(sf::RenderWindow* window, std::map<std::string,int>* supportedKeys, std::stack<State*>* states);
        virtual ~GameState();

        void updateInput(const float& dt);
        void update(const float& dt);
        void render(sf::RenderTarget* target = NULL);

    protected:

    private:
        Entity player;

        void initKeybinds();
};

#endif // GAMESTATE_H
