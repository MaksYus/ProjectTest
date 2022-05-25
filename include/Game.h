#ifndef GAME_H
#define GAME_H

#include<MainMenuState.h>

class Game
{
    public:
        Game();
        virtual ~Game();

        void endAplication();
        void run();
        void render();

        void updateDt();
        void updateSFMLEvent();
        void update();

    protected:

    private:
        sf::RenderWindow *window;
        sf::Event sfEvent;

        sf::Clock dtClock;
        float dt;

        std::stack<State*> states;


        std::map<std::string, int> supportedKeys;

        void initWindow();
        void initKeys();
        void initStates();
};

#endif // GAME_H
