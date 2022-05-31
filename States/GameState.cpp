#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states):
     State(window, supportedKeys,states)
{
    this->initKeybinds();
}

GameState::~GameState()
{
    //dtor
}

void GameState::initKeybinds(){
    std::ifstream ifs("Config/GameState_Keybinds.ini");

    if(ifs.is_open()){
            std::string key = "";
            std::string key2 = "";

            while (ifs >> key >> key2){
                this->keybinds[key] = this->supportedKeys->at(key2);
            }
    }
    else {
        std::cout << "ERROR! не удалось открыть Config/GameState_Keybinds.ini" << std::endl;
    }
    ifs.close();
}

void GameState::update(const float& dt){
    this->updateMousePosition();
    this->updateInput(dt);
    this->player.update(dt);
}

void GameState::render(sf::RenderTarget* target){
    if (!target)
        target = this->window;
    this->player.render(target);
}


void GameState::updateInput(const float& dt){

    //Update player Input
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
            this->player.move(dt, 0.f, -1.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
            this->player.move(dt, 0.f, 1.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
            this->player.move(dt, -1.f, 0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
            this->player.move(dt, 1.f, 0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
            this->endState();
}
