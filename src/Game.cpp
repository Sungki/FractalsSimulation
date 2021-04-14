#include "Game.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

Game::Game()
{
    window.create(sf::VideoMode(1024, 768, 32), "Fractals");
}

void Game::HandleInput()
{
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) window.close();
    }
}

void Game::Run()
{
    while (window.isOpen()) {
        HandleInput();
        Render();
    }
}

void Game::Render()
{
    window.display();
}