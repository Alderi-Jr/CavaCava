#include "Grid.h"

Grid::Grid(int rows, int cols, int cellSize)
    : rows(rows), cols(cols), cellSize(cellSize)
{
    cells.resize(rows, std::vector<CellType>(cols, CellType::Empty));
}

void Grid::setCell(int r, int c, CellType type) {
    if (r >= 0 && r < rows && c >= 0 && c < cols) {
        cells[r][c] = type;
    }
}

CellType Grid::getCell(int r, int c) const {
    return cells[r][c];
}

void Grid::draw(sf::RenderWindow& window) const {
    sf::RectangleShape rect(sf::Vector2f(cellSize - 1, cellSize - 1));

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {

            switch (cells[r][c]) {
                case CellType::Empty:
                    rect.setFillColor(sf::Color(60, 60, 60));
                    break;

                case CellType::Wall:
                    rect.setFillColor(sf::Color::Blue);
                    break;

                case CellType::Supply:
                    rect.setFillColor(sf::Color::Yellow);
                    break;

                case CellType::Agent:
                    rect.setFillColor(sf::Color::Green);
                    break;

                case CellType::Zombie:
                    rect.setFillColor(sf::Color::Red);
                    break;
            }

            rect.setPosition(c * cellSize, r * cellSize);
            window.draw(rect);
        }
    }
}

int Grid::getRows() const { return rows; }
int Grid::getCols() const { return cols; }
int Grid::getCellSize() const { return cellSize; }
