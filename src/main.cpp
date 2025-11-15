#include <SFML/Graphics.hpp>
#include "Grid.h"

int main() {
    const int rows = 20;
    const int cols = 20;
    const int cellSize = 30;

    sf::RenderWindow window(sf::VideoMode(cols * cellSize, rows * cellSize), "GridWorld - Ambiente Inicial");

    Grid grid(rows, cols, cellSize);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        grid.draw(window);

        window.display();
    }

    return 0;
}
