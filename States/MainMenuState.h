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
        void updateButtons();
        void update(const float& dt);
        void renderButtons(sf::RenderTarget* target = NULL);
        void render(sf::RenderTarget* target = NULL);

    protected:

    private:
        sf::RectangleShape background;
        sf::Font font;

        std::map<std::string, Button*> buttons;

        void initFonts();
        void initKeybinds();
        void initButtons();
};

#endif // MAINMENUSTATE_H
