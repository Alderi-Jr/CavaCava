#ifndef GRID_H
#define GRID_H

#include <SFML/Graphics.hpp>
#include <vector>

enum class CellType {
    Empty,
    Wall,
    Supply,
    Agent,
    Zombie
};

class Grid {
private:
    int rows;
    int cols;
    int cellSize;

    std::vector<std::vector<CellType>> cells;

public:
    Grid(int rows, int cols, int cellSize);

    void setCell(int r, int c, CellType type);
    CellType getCell(int r, int c) const;

    void draw(sf::RenderWindow& window) const;

    int getRows() const;
    int getCols() const;
    int getCellSize() const;
};

#endif
