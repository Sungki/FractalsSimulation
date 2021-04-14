#include "Game.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "TreeFractal.h"

#define WIDTH 1024
#define HEIGHT 1024

Game::Game() : it(0), flag(false)
{
    window.create(sf::VideoMode(WIDTH, HEIGHT, 32), "Fractals");
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
    window.setFramerateLimit(30);

    while (window.isOpen()) {
        HandleInput();
        Render();
    }
}

void Game::Render()
{
    window.clear();

    TreeFractal tf = TreeFractal();
    tf.setStartLocation(WIDTH / 2, HEIGHT - 100);
    tf.setLeftAngle(30);
    tf.setRightAngle(17);
    tf.setNumberOfIterations(it);
    tf.setInitWidth(12);
    tf.setInitHeight(96);
    sf::Color brown = sf::Color(70, 190, 63);
    tf.setColor(brown);
    tf.setScalingFactor(0.88);
    tf.Render(window);

    if (!flag)
    {
        it++;
        if (it > 15) flag = true;
    }
    else
    {
        it--;
        if (it < 0) flag = false;
    }

    window.display();
}