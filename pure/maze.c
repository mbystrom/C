#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define HEIGHT 20
#define WIDTH 20

int grid[HEIGHT][WIDTH] = { 0 };

const short N = 1;
const short S = 2;
const short E = 4;
const short W = 8;

int DX[9];
int DY[9];
int opposite[9];

int CarvePassage(int cx, int cy);
int shuffle(int array[], int size);
unsigned char isOut(int x, int y);
int PrintMaze();

int main ()
{
    srand(time(NULL));
    
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

    CarvePassage(0,0);
    PrintMaze();
}

int CarvePassage (int cx, int cy)
{
    int directions[4] = { N, S, E, W };
    shuffle(directions, 4);
    for (int i = 0; i < 4; i++) {
        int nx = cx + DX[directions[i]];
        int ny = cy + DY[directions[i]];

        if (isOut(nx, ny) == 1) continue;

        if (grid[ny][nx] == 0) {
            grid[cy][cx] |= directions[i];
            grid[ny][nx] |= opposite[directions[i]];
            CarvePassage(nx, ny);
        }
    }
}

unsigned char isOut (int x, int y)
{
    if (x < 0 || x >= WIDTH) return 1;
    if (y < 0 || y >= HEIGHT) return 1;
    return 0;
}

int shuffle (int array[], int length)
{
    for (int i = length-1; i > 0; i--) {
        int j = rand() % i;
        int temp = array[j];
        array[j] = array[i];
        array[i] = temp;
    }
}

int PrintMaze ()
{
    printf(" ");
    for (int x = 0; x < WIDTH*2-1; x++) {
        printf("_");
    }
    printf("\n");

    for (int y = 0; y < HEIGHT; y++) {
        printf("|");
        for (int x = 0; x < WIDTH; x++) {
            if ((grid[y][x] & S) != 0) {
                printf(" ");
            } else {
                printf("_");
            }

            if ((grid[y][x] & E) != 0) {
                if (((grid[y][x] | grid[y][x+1]) & S) != 0) {
                    printf(" ");
                } else {
                    printf("_");
                }
            } else {
                printf("|");
            }
        }
        printf("\n");
    }
}
