#ifndef STATE_H
#define STATE_H

#include"Player.h"

class State
{
    public:
        State(sf::RenderWindow* window, std::map<std::string,int>* supportedKeys, std::stack<State*>* states);
        virtual ~State();

        const bool& getQuit() const;
        void endState();
        void pauseState();
        void unpausedState();

        virtual void updateMousePosition();
        virtual void updateInput(const float& dt) = 0;
        virtual void update(const float& dt) = 0;
        virtual void render(sf::RenderTarget* target = NULL) = 0;

    protected:
        std::stack<State*>* states;
        sf::RenderWindow* window;
        std::map<std::string,int>* supportedKeys;
        std::map<std::string,int> keybinds;
        bool quit;
        bool paused;

        sf::Vector2i mousePosScreen;
        sf::Vector2i mousePosWindow;
        sf::Vector2f mousePosView;

        std::map<std::string, sf::Texture> textures;

        virtual void initKeybinds() = 0;
    private:


};

#endif // STATE_H
