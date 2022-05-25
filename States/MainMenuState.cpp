#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys):
     State(window, supportedKeys)
{
    this->initFonts();
    this->initKeybinds();

    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState()
{
    //dtor
}

void MainMenuState::initFonts(){
    if(!this->font.loadFromFile("Fonts/Dosis-Light.ttf")){
        throw("ERROR::COULD NOT LOAD FONT");
    }
}

void MainMenuState::initKeybinds(){
    std::ifstream ifs("Config/GameState_Keybinds.ini");

    if(ifs.is_open()){
            std::string key = "";
            std::string key2 = "";

            while (ifs >> key >> key2){
                this->keybinds[key] = this->supportedKeys->at(key2);
            }
    }
    ifs.close();
}

void MainMenuState::update(const float& dt){
    this->updateMousePosition();
    this->updateInput(dt);

    system("cls");
    std::cout << this->mousePosView.x << " " << this->mousePosView.y << "\n";
}

void MainMenuState::render(sf::RenderTarget* target){
    if (!target)
        target = this->window;
    target->draw(this->background);
}

void MainMenuState::endState(){
    std::cout << "EndState\n";
}

void MainMenuState::updateInput(const float& dt){
    this->checkForQuit();

  //  if(sf::Keyboard::isKeyPressed(sf::Keyboard::G))

}
