#include "Grid.h"

Grid::Grid(int rows, int cols, int cellSize)
    : rows(rows), cols(cols), cellSize(cellSize)
{
    cells.resize(rows, std::vector<CellType>(cols, CellType::Empty));
}

void Grid::setCell(int row, int col, CellType type) {
    cells[row][col] = type;
}

void Grid::draw(sf::RenderWindow& window) {
    sf::RectangleShape rect(sf::Vector2f(cellSize - 1, cellSize - 1));

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {

            switch (cells[r][c]) {
                case CellType::Empty:  rect.setFillColor(sf::Color::Black); break;
                case CellType::Wall:   rect.setFillColor(sf::Color::White); break;
                case CellType::Player: rect.setFillColor(sf::Color::Green); break;
                case CellType::Zombie: rect.setFillColor(sf::Color::Red); break;
                case CellType::Supply: rect.setFillColor(sf::Color::Yellow); break;
            }

            rect.setPosition(c * cellSize, r * cellSize);
            window.draw(rect);
        }
    }
}
