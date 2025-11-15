#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

enum class CellType { Empty, Wall, Player, Zombie, Supply };

class Grid {
public:
    Grid(int rows, int cols, int cellSize);

    void setCell(int row, int col, CellType type);
    void draw(sf::RenderWindow& window);

private:
    int rows, cols, cellSize;
    std::vector<std::vector<CellType>> cells;
};
