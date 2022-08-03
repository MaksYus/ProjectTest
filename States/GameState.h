#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "PauseMenu.h"

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
        PauseMenu pmenu;

        Player *player;

        void initKeybinds();
        void initTextures();
        void initPlayers();
};

#endif // GAMESTATE_H
