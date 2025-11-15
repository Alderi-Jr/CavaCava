#include <SFML/Graphics.hpp>
#include "Grid.h"

int main() {
    const int cellSize = 40;
    const int rows = 10;
    const int cols = 10;

    sf::RenderWindow window(
        sf::VideoMode(cols * cellSize, rows * cellSize),
        "GridWorld - Base"
    );

    Grid grid(rows, cols, cellSize);

    // Exemplos de células
    grid.setCell(2, 2, CellType::Agent);
    grid.setCell(4, 4, CellType::Supply);
    grid.setCell(5, 5, CellType::Zombie);
    grid.setCell(0, 0, CellType::Wall);

    while (window.isOpen()) {
        sf::Event event{};
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
