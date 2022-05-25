#ifndef STATE_H
#define STATE_H

#include"Entity.h"

class State
{
    public:
        State(sf::RenderWindow* window, std::map<std::string,int>* supportedKeys);
        virtual ~State();

        const bool& getQuit() const;
        virtual void checkForQuit();
        virtual void endState() = 0;

        virtual void updateMousePosition();
        virtual void updateInput(const float& dt) = 0;
        virtual void update(const float& dt) = 0;
        virtual void render(sf::RenderTarget* target = NULL) = 0;

    protected:
        sf::RenderWindow* window;
        std::map<std::string,int>* supportedKeys;
        std::map<std::string,int> keybinds;
        bool quit;

        sf::Vector2i mousePosScreen;
        sf::Vector2i mousePosWindow;
        sf::Vector2f mousePosView;

        std::vector<sf::Texture> textures;

        virtual void initKeybinds() = 0;
    private:


};

#endif // STATE_H