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

public:
    Game();
    void Run();
};
