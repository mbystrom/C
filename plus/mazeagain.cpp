#include <iostream>
#include <cstdlib>
#include <ctime>

// directions (must correspond to bits)
enum Directions
{
    const unsigned char N = 1;
    const unsigned char S = 2;
    const unsigned char E = 4;
    const unsigned char W = 8;
}

// arrays with directions corresponding to relative translation
int DX[9];
int DY[9];

// just the opposite
int Opposite[9];

// width and height of the maze
int width = 10;
int height = 10;

// function forward-declaration
void CarveMaze (int cx, int cy, int (*grid)[width][height]);
bool isOut (int x, int y);
void shuffleFour (int *array);
void PrintMaze (int (*grid)[height][width])

int main ()
{
    // seeding random
    std::srand(std::time(0));

    // assign values to direction arrays
    DX[N] = 0;
    DX[S] = 0;
    DX[E] = 1;
    DX[W] = -1;

    DY[N] = -1;
    DY[S] = 1;
    DY[E] = 0;
    DY[W] = 0;

    Opposite[N] = S;
    Opposite[S] = N;
    Opposite[E] = W;
    Opposite[W] = E;

    // initialize the map and start carving it
    int map[height][width] = { 0 };
    CarveMaze(0, 0, &map);

    // print the result
    PrintMaze(&map);
}

void CarveMaze (int cx, int cy, int (*grid)[height][width])
{
    int directions[4] = { N, S, E, W };
    shuffleFour(&directions);

    for (int i = 0; i < (sizeof(directions)/sizeof(directions[0])); i++) {
        int nx = cx + DX[directions[i]];
        int ny = cy + DY[directions[i]];

        if (isOut(nx, ny)) continue;

        if (*grid[ny][nx] == 0) {
            *grid[cy][cx] |= directions[i];
            *grid[ny][nx] |= Opposite[directions[i]];
            CarveMaze(nx, ny, &*grid);
        }
    }
}

void shuffleFour (int *array)
{
    int length = sizeof(*array) / sizeof(*array[0]);
    for (int i = length - 1; i > 0; i--) {
        j = std::rand() % (i + 1);
        int temp = *array[j];
        *array[j] = *array[i];
        *array[i] = temp;
    }
}

bool isOut (int x, int y)
{
    if (x < 0 || x >= width) return true;
    if (y < 0 || y >= height) return true;
    return false;
}

void PrintMaze (int (*grid)[height][width])
{
    using namespace std;
    
    for (int x = 0; x < width; x++) {
        cout << "__";
    }
    cout << endl;
    for (int y = 0; y < height; y++) {
        cout << "|";
        for (int x = 0; x < width; x++) {
            if ((*grid[y][x] & S) != 0) {
                cout << " ";
            } else {
                cout << "_";
            }
            
            if ((*grid[y][x] & E) != 0) {
                if (((*grid[y][x] | *grid[y][x+1]) & S) != 0) {
                    cout << " ";
                } else {
                    cout << "_";
                }
            } else {
                cout << "|";
            }
        }
        cout << endl;
    }
}

