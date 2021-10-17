#include <iostream>
#include "SFML/Graphics.hpp"

int main(int argc, const char **argv)
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Shitty - Game");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    sf::Event event;
    bool isRunning = true;

    while (window.isOpen())
    {
        std::cout << "game started" << std::endl;
        // Handle Keyboard Inputs
        while (window.pollEvent(event))
        {
            // Handle Close
            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
            {
                isRunning = false;
                break;
            }

            // Handle Movements
        }

        // Calcute and Define Logic
        if (!isRunning)
            window.close();


        // Rerender Items
        window.clear();
        // window.draw(welcomeText);
        window.display();
    }

    return EXIT_SUCCESS;
}