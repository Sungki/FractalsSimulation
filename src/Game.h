#pragma once
#include <iostream>
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class Game
{
private:
    sf::RenderWindow window;

    void Render();
    void HandleInput();

    int it;
    bool flag;

public:
    Game();
    void Run();
};
