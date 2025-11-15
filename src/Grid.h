#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

enum class CellType {
    Empty,
    Wall,
    Agent,
    Zombie,
    Supply,
    Goal
};

class Grid {
private:
    int rows;
    int cols;
    int cellSize;

public:
    std::vector<std::vector<CellType>> cells;

    Grid(int rows, int cols, int cellSize);

    void draw(sf::RenderWindow& window);

    // Getters úteis
    int getRows() const { return rows; }
    int getCols() const { return cols; }
    int getCellSize() const { return cellSize; }
};
