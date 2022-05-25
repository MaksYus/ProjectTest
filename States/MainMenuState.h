#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include"GameState.h"
#include"Button.h"

class MainMenuState:
    public State
{
     public:
        MainMenuState(sf::RenderWindow* window, std::map<std::string,int>* supportedKeys);
        virtual ~MainMenuState();

        void endState();

        void updateInput(const float& dt);
        void update(const float& dt);
        void render(sf::RenderTarget* target = NULL);

    protected:

    private:
        sf::RectangleShape background;
        sf::Font font;
        void initFonts();
        void initKeybinds();
};

#endif // MAINMENUSTATE_H
