#include "Game.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "TreeFractal.h"

#define WIDTH 1024
#define HEIGHT 768

Game::Game() : it(0), flag(false)
{
    window.create(sf::VideoMode(WIDTH, HEIGHT, 32), "Fractals");
}

void Game::HandleInput()
{
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) window.close();

        if (event.type == sf::Event::KeyPressed) it = it + 0.0001;
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

    for (int i = 0; i < 1000; i++)
    {
        float dst = (i / (1000 - 1.0f)) * 300;
        float angle = 2 * M_PI * it * i;

        float x = dst * std::cos(angle);
        float y = dst * std::sin(angle);

        sf::CircleShape circle = sf::CircleShape(2);
        circle.setPosition(x + 500,y + 400);
        window.draw(circle);
    }

    it = it + 0.00001;

/*    TreeFractal tf = TreeFractal();
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
    }*/

    window.display();
}