#include "EditorState.h"

EditorState::EditorState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states):
     State(window, supportedKeys, states)
{
    this->initVariables();
    this->initBackground();
    this->initFonts();
    this->initKeybinds();
    this->initButtons();
}

EditorState::~EditorState()
{
    //dtor
}

void EditorState::initVariables(){

}

void EditorState::initBackground(){
}

void EditorState::initFonts(){
    if(!this->font.loadFromFile("Fonts/Dosis-Light.ttf")){
        throw("ERROR::COULD NOT LOAD FONT");
    }
}

void EditorState::initKeybinds(){
    std::ifstream ifs("Config/EditorState_Keybinds.ini");

    if(ifs.is_open()){
            std::string key = "";
            std::string key2 = "";

            while (ifs >> key >> key2){
                this->keybinds[key] = this->supportedKeys->at(key2);
            }
    }
    else{
        std::cout << "ERROR! Не удалось открыть Config/MainMenu_Keybinds.ini" << std::endl;
    }
    ifs.close();
}

void EditorState::initButtons(){

}

void EditorState::update(const float& dt){
    this->updateMousePosition();
    this->updateInput(dt);

    this->updateButtons();

}

void EditorState::updateButtons(){

    this->it = this->buttons.begin();
    for (int i = 0; this->it != this->buttons.end(); this->it++, i++)
        this->it->second->update(this->mousePosView);

}

void EditorState::renderButtons(sf::RenderTarget* target){
    this->it = this->buttons.begin();
    for (int i = 0; this->it != this->buttons.end(); this->it++, i++)
        this->it->second->render(target);
}

void EditorState::render(sf::RenderTarget* target){
    if (!target)
        target = this->window;
    this->renderButtons(target);

}

void EditorState::updateInput(const float& dt){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
        this->endState();
}
