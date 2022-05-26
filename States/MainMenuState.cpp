#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys):
     State(window, supportedKeys)
{
    this->initFonts();
    this->initKeybinds();
    this->initButtons();

    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState()
{
    for(auto& item : this->buttons)
        delete item.second;
   // delete this->gamestate_btn;
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

void MainMenuState::initButtons(){
    this->buttons["GAME_STATE"] = new Button(100.f, 100.f, 150.f, 50.f,
                                     &this->font, "New Game",
                                      sf::Color(70, 70, 70, 200),
                                     sf::Color(20,20,20,200),
                                     sf::Color(150, 150, 150, 255));
     this->buttons["EXIT_STATE"] = new Button(100.f, 300.f, 150.f, 50.f,
                                     &this->font, "Quit",
                                      sf::Color(70, 70, 70, 200),
                                     sf::Color(20,20,20,200),
                                     sf::Color(150, 150, 150, 255));

}

void MainMenuState::update(const float& dt){
    this->updateMousePosition();
    this->updateInput(dt);

    this->updateButtons();

}

void MainMenuState::updateButtons(){
    for(auto &item : this->buttons){
        item.second->update(this->mousePosView);
    }

    if(this->buttons["EXIT_STATE"]->isPressed()){
        this->quit = true;
    }

    if(this->buttons["GAME_STATE"]->isPressed()){
        //this->states.push(new GameState(this->window, &this->supportedKeys));
    }
}

void MainMenuState::renderButtons(sf::RenderTarget* target){
    for(auto &item : this->buttons){
        item.second->render(target);
    }
}

void MainMenuState::render(sf::RenderTarget* target){
    if (!target)
        target = this->window;
    target->draw(this->background);
    this->renderButtons(target);
}

void MainMenuState::endState(){
    std::cout << "EndState\n";
}

void MainMenuState::updateInput(const float& dt){
    this->checkForQuit();

  //  if(sf::Keyboard::isKeyPressed(sf::Keyboard::G))

}
