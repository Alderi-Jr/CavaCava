#include "Grid.h"

Grid::Grid(int rows, int cols, int cellSize)
    : rows(rows), cols(cols), cellSize(cellSize)
{
    cells.resize(rows, std::vector<CellType>(cols, CellType::Empty));

        // Cluster 1
        cells[3][5] = CellType::Wall;
        cells[4][5] = CellType::Wall;
        cells[3][6] = CellType::Wall;
        cells[5][5] = CellType::Wall;
        cells[4][6] = CellType::Wall;

        // Cluster 2
        cells[8][10] = CellType::Wall;
        cells[8][11] = CellType::Wall;
        cells[9][10] = CellType::Wall;
        cells[9][11] = CellType::Wall;

        // Cluster 3
        cells[14][3] = CellType::Wall;
        cells[15][3] = CellType::Wall;
        cells[14][4] = CellType::Wall;
        cells[14][2] = CellType::Wall;

        // Cluster 4
        cells[17][15] = CellType::Wall;
        cells[18][15] = CellType::Wall;
        cells[17][16] = CellType::Wall;
        cells[16][15] = CellType::Wall;


        cells[2][2]   = CellType::Supply;
        cells[6][10]  = CellType::Supply;
        cells[14][3]  = CellType::Supply;
        cells[17][12] = CellType::Supply;


        cells[8][8]   = CellType::Zombie;
        cells[12][5]  = CellType::Zombie;
        cells[4][14]  = CellType::Zombie;
        cells[16][16] = CellType::Zombie;


        cells[19][18] = CellType::Goal;


        cells[0][0] = CellType::Agent;

}


void Grid::draw(sf::RenderWindow& window) {
    sf::RectangleShape square(sf::Vector2f(cellSize - 1, cellSize - 1));

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {

            CellType t = cells[r][c];

            switch (t) {
                case CellType::Empty:   square.setFillColor(sf::Color(255, 255, 255)); break;
                case CellType::Wall:    square.setFillColor(sf::Color(150,150,150)); break;
                case CellType::Agent:   square.setFillColor(sf::Color::Green); break;
                case CellType::Zombie:  square.setFillColor(sf::Color::Red); break;
                case CellType::Supply:  square.setFillColor(sf::Color::Yellow); break;
                case CellType::Goal:    square.setFillColor(sf::Color::Cyan); break;
            }

            square.setPosition(c * cellSize, r * cellSize);
            window.draw(square);
        }
    }
}
