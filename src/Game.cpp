#include "Game.h"

#include<iostream>
#include<ctime>
#include<cstdlib>

#include<Game.h>

void Game::initWindow(){
    //выгрузка настроек окна из файла
    std::ifstream ifs("Config/window.ini");

    std::string title = "None";
    sf::VideoMode window_bounds(800,600);
    unsigned framerate_limit = 120;
    bool vertical_sync_enabled = false;
    if(ifs.is_open()){
        std::getline(ifs,title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
    }
     ifs.close();
    //конец выгрузки

    this->window = new sf::RenderWindow(window_bounds, title);
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);


}

void Game::initKeys(){
    std::ifstream ifs("Config/Supported_Keys.ini");

    if(ifs.is_open()){
            std::string key = "";
            int key_value = 0;

            while (ifs >> key >> key_value){
                this->supportedKeys[key] = key_value;
            }
    }
    ifs.close();
}

void Game::initStates(){
    this->states.push(new MainMenuState(this->window, &this->supportedKeys));
}

Game::Game(){
    this->initWindow();
    this->initKeys();
    this->initStates();
}

Game::~Game(){
    delete this->window;
    while(!this->states.empty()){
        delete this->states.top();
        this->states.pop();
    }
}

void Game::run(){
    while(this->window->isOpen()){
        this->updateDt();
        this->update();
        this->render();
    }
}

void Game::render(){
    this->window->clear();
    if(!this->states.empty())
        this->states.top()->render(this->window);
    this->window->display();
}

void Game::updateSFMLEvent(){
    while(this->window->pollEvent(this->sfEvent)){
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::update(){
    this->updateSFMLEvent();

     if(!this->states.empty())
     {
         this->states.top()->update(this->dt);

         if (this->states.top()->getQuit()){
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
         }
     }
    else{
        this->endAplication();
        this->window->close();
    }

}

void Game::updateDt(){
    this->dt = this->dtClock.restart().asSeconds();

   // system("cls");
    //std::cout << this->dt <<"\n";
}

void Game::endAplication(){
    std::cout << "Ending App!\n";
}
