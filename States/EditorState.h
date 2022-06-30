#ifndef EDITORSTATE_H
#define EDITORSTATE_H

#include "State.h"
#include"GameState.h"
#include"Button.h"

class EditorState : public State
{
    public:
        EditorState(sf::RenderWindow* window, std::map<std::string,int>* supportedKeys, std::stack<State*>* states);
        virtual ~EditorState();

        void updateInput(const float& dt);
        void updateButtons();
        void update(const float& dt);
        void renderButtons(sf::RenderTarget* target = NULL);
        void render(sf::RenderTarget* target = NULL);
    protected:

    private:
        sf::Font font;

        std::map<std::string, Button*> buttons;
        std::map<std::string, Button*>::iterator it = buttons.begin();

        void initVariables();
        void initBackground();
        void initFonts();
        void initKeybinds();
        void initButtons();
};

#endif // EDITORSTATE_H