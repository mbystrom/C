#include <iostream>
#include <vector>

using namespace std;

int width = 40;
int height = 40;

enum Directions { N = 1, S = 2, E = 4, W = 8 };
//            0   N  S  3  E  5  6  7   W
int DX[9] = { 0,  0, 0, 0, 1, 0, 0, 0, -1 };
int DY[9] = { 0, -1, 1, 0, 0, 0, 0, 0,  0 };

class Tile {
public:
    Tile (int _x, int _y) {
        x = _x;
        y = _y;
        isFloor = false;
    }
    Tile (int _x, int _y, bool f) {
        x = _x;
        y = _y;
        isFloor = f;
    }
    int x;
    int y;
    bool isFloor;
};

bool isOut (int x, int y) {
    if (x < 0 || x >= width)  return true;
    if (y < 0 || y >= height) return true;
    return false;
}

vector<Tile> Fill (vector<vector<Tile>>* grid, Tile start) {
    vector<vector<int>> flags;
    for (int y = 0; y < (*grid).size(); y++) {
        flags.push_back(vector<int>());
        for (int x = 0; x < (*grid)[0].size(); x++) {
            int push;
            ((*grid)[y][x].isFloor) ? push = 0 : push = 1;
            flags[y].push_back(push);
        }
    }

    vector<Tile> filledTiles;
    vector<Tile> queue;
    queue.push_back(start);

    while (queue.size() > 0) {
        Tile tile = queue[0];
        filledTiles.push_back(tile);
        queue.erase(queue.begin());

        int directions[4] = { N, S, E, W };
        for (int direction : directions) {
            int x = tile.x + DX[direction];
            int y = tile.y + DY[direction];

            if (isOut(x, y) || flags[y][x] == 1) continue;

            if ((*grid)[y][x].isFloor) {
                flags[y][x] = 1;
                queue.push_back(Tile(y, x, true));
            }
        }
    }
    cout << queue.size() << endl;
    return filledTiles;
}

int main () {
    vector<vector<Tile>> grid;
    for (int y = 0; y < height; y++) {
        grid.push_back(vector<Tile>());
        for (int x = 0; x < width; x++) {
            bool f;
            if (x == 0 || y == 0 || x == width - 1 || y == height - 1) {
                f = false;
            } else {
                f = true;
            }
            grid[y].push_back(Tile(x, y, f));
        }
    }

    vector<Tile> filled = Fill(&grid, Tile(1, 1, true));

    int count11 = 0;
    for (Tile tile : filled) {
        if (tile.x == 1 && tile.y == 1) count11++;
        cout << "Tile is (" << tile.x << ", " << tile.y << ") - ";
        (tile.isFloor) ? cout << "tile is floor\n" : cout << "tile is wall";
    }
}
