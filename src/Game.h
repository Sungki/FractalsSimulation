#pragma once
#include <iostream>
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

# define M_PI           3.14159265358979323846

class Game
{
private:
    sf::RenderWindow window;

    void Render();
    void HandleInput();

    float it;
    bool flag;

public:
    Game();
    void Run();
};
