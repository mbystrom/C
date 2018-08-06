#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

const int width = 20;
const int height = 20;

int grid[height][width] = { 0 };

const short N = 1;
const short S = 2;
const short E = 4;
const short W = 8;

int DX[9];
int DY[9];
int opposite[9];

void shuffle(int array[], int n);
void CarveMaze(int x, int y);
void PrintMaze();
bool isOut(int cx, int cy);

int main ()
{
    std::srand(std::time(0));
    
    DX[N] = 0;
    DX[S] = 0;
    DX[E] = 1;
    DX[W] = -1;
    
    DY[N] = -1;
    DY[S] = 1;
    DY[E] = 0;
    DY[W] = 0;
    
    opposite[N] = S;
    opposite[S] = N;
    opposite[E] = W;
    opposite[W] = E;

    CarveMaze(0, 0);
    PrintMaze();
}

void CarveMaze (int cx, int cy)
{
    int directions[4] = { N, S, E, W };
    shuffle(directions, 4);
    for (int i = 0; i < 4; i++) {
        int nx = cx + DX[directions[i]];
        int ny = cy + DY[directions[i]];
        
        if (isOut(nx, ny)) continue;
        
        if (grid[ny][nx] == 0) {
            grid[cy][cx] |= directions[i];
            grid[ny][nx] |= opposite[directions[i]];
            CarveMaze(nx, ny);
        }
    }
}

bool isOut (int x, int y)
{
    if (x < 0 || x >= width) return true;
    if (y < 0 || y >= height) return true;
    return false;
}

void PrintMaze ()
{
    using namespace std;
    
    cout << " ";
    for (int x = 0; x < width*2-1; x++) {
        cout << "_";
    }
    cout << endl;
    
    for (int y = 0; y < height; y++) {
        cout << "|";
        for (int x = 0; x < width; x++) {
            if ((grid[y][x] & S) != 0) {
                cout << " ";
            } else {
                cout << "_";
            }
            
            if ((grid[y][x] & E) != 0) {
                if (((grid[y][x] | grid[y][x+1]) & S) != 0) {
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

void shuffle (int array[], int n)
{    
    for (int i = n-1; i > 0; i--) {
        int j = std::rand() % i;
        int temp = array[j];
        array[j] = array[i];
        array[i] = temp;
    }
}
