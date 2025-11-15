#include <SFML/Graphics.hpp>
#include "Grid.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(600, 600), "CavaCava");

    Grid grid(20, 20, 30);
    grid.setCell(5, 5, CellType::Player);
    grid.setCell(7, 10, CellType::Zombie);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        grid.draw(window);
        window.display();
    }

    return 0;
}
