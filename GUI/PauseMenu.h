#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include<iostream>
#include<map>
#include<fstream>
#include<sstream>
#include<vector>

#include"SFML/System.hpp"
#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
#include"SFML/Audio.hpp"
#include"SFML/Network.hpp"

class PauseMenu
{
    public:
        PauseMenu(f::VideoMode& vm, sf::Font& font);
        virtual ~PauseMenu();

    protected:

    private:

};

#endif // PAUSEMENU_H
