#include "PauseMenu.h"

PauseMenu::PauseMenu(sf::RenderWindow& window)
{
    this->background.setSize(sf::Vector2f(static_cast<float>(window.getSize().x),static_cast<float>(window.getSize().y)));
    this->background.setFillColor(sf::Color(20,20,20,100));

    this->container.setSize(sf::Vector2f(static_cast<float>(window.getSize().x) / 4.f,static_cast<float>(window.getSize().y)));
    this->container.setFillColor(sf::Color(20,20,20,200));
    this->container.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 2.f - this->container.getSize().x / 2.f, 0));

    this->initFonts();
    this->initVariables();
    this->initKeybinds();
    this->initButtons();
}

PauseMenu::~PauseMenu()
{
    for(this->it_buttons = this->buttons.begin();it_buttons!= this->buttons.end();it_buttons++){
        delete this->it_buttons->second;
    }
}

void PauseMenu::initButtons(){
    this->buttons["CONTINUE"] = new Button(
                                             1600.f, 100.f, 150.f, 50.f,
                                             &this->font, "Continue", 30,
                                             sf::Color(255,255,255,200), sf::Color(255,255,255,200), sf::Color(255, 255, 255, 200),
                                             sf::Color(70, 70, 70, 200),
                                             sf::Color(150,150,150,200),
                                             sf::Color(20, 20, 20, 255));
    this->buttons["EXIT"] = new Button(
                                             1600.f, 250.f, 150.f, 50.f,
                                             &this->font, "Exit", 30,
                                             sf::Color(255,255,255,200), sf::Color(255,255,255,200), sf::Color(255, 255, 255, 200),
                                             sf::Color(70, 70, 70, 200),
                                             sf::Color(150,150,150,200),
                                             sf::Color(20, 20, 20, 255));
}

void PauseMenu::initFonts(){
    if(!this->font.loadFromFile("Fonts/Dosis-Light.ttf")){
        throw("ERROR::PauseMenu::COULD NOT LOAD FONT");
    }
}

void PauseMenu::initKeybinds(){

}

void PauseMenu::initVariables(){
    this->background.setSize(sf::Vector2f());
}

void PauseMenu::update(){

}

void PauseMenu::updateInput(){

}

void PauseMenu::updateButtons(){

}

void PauseMenu::renderButtons(sf::RenderTarget& target){
    for (this->it_buttons = this->buttons.begin(); this->it_buttons != this->buttons.end(); this->it_buttons++)
        this->it_buttons->second->render(target);
}

void PauseMenu::render(sf::RenderTarget& target){
    target.draw(this->background);
    target.draw(this->container);
    this->renderButtons(target);
}
