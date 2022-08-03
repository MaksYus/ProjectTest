#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include "Button.h"

class PauseMenu
{
    public:
        PauseMenu(sf::RenderWindow& window);
        virtual ~PauseMenu();

        void updateInput();
        void updateButtons();
        void update();
        void renderButtons(sf::RenderTarget& target);
        void render(sf::RenderTarget& target);

    protected:

    private:
        sf::Font font;
        sf::RectangleShape background;
        sf::RectangleShape container;

        std::map<std::string, Button*> buttons;
        std::map<std::string, Button*>::iterator it_buttons = buttons.begin();
        std::map<std::string,int> keybinds;


        void initButtons();
        void initFonts();
        void initKeybinds();
        void initVariables();

};

#endif // PAUSEMENU_H
