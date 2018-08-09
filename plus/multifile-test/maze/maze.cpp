#include <iostream>
#include <cstdlib>
#include <ctime>
#include "matrix.h"

enum { N = 1, S = 2, E = 4, W = 8 };

int DX[9];
int DY[9];
int OPPOSITE[9];

int h;
int w;

std::vector<std::vector<int>> grid;

void shuffle(int arr[], int length);
void CarveMaze(int cx, int cy);
void PrintMaze(std::vector<std::vector<int>> grid, int height, int width);
bool isOut(int x, int y);

std::vector<std::vector<int>> GenerateMaze(int height, int width)
{
	h = height;
	w = width;

	std::srand(std::time(0));

	DX[N] = 0;
	DX[S] = 0;
	DX[E] = 1;
	DX[W] = -1;

	DY[N] = -1;
	DY[S] = 1;
	DY[E] = 0;
	DY[W] = 0;

	OPPOSITE[N] = S;
	OPPOSITE[S] = N;
	OPPOSITE[E] = W;
	OPPOSITE[W] = E;

	grid = generate_matrix(height, width, 0);

	CarveMaze(0, 0);

	return grid;
}

void CarveMaze(int cx, int cy)
{
	int directions[4] = { N, S, E, W };
	shuffle(directions, 4);
	for (int i = 0; i < 4; i++) {
		int nx = cx + DX[directions[i]];
		int ny = cy + DY[directions[i]];

		if (isOut(nx, ny)) continue;

		if (grid[ny][nx] == 0) {
			grid[cy][cx] |= directions[i];
			grid[ny][nx] |= OPPOSITE[directions[i]];
			CarveMaze(nx, ny);
		}
	}
}

bool isOut(int x, int y)
{
	if (x < 0 || x >= w) return true;
	if (y < 0 || y >= h) return true;
	return false;
}

void PrintMaze(std::vector<std::vector<int>> grid, int height, int width)
{
	using namespace std;

	cout << " ";
	for (int x = 0; x < width * 2 - 1; x++) {
		cout << "_";
	}
	cout << endl;

	int x, y;
	for (y = 0; y < height; y++) {
		cout << "|";
		for (x = 0; x < width; x++) {
			if ((grid[y][x] & S) != 0) {
				cout << " ";
			}
			else {
				cout << "_";
			}

			if ((grid[y][x] & E) != 0) {
				if (((grid[y][x] | grid[y][x + 1]) & S) != 0) {
					cout << " ";
				}
				else {
					cout << "_";
				}
			}
			else {
				cout << "|";
			}
		}
		cout << endl;
	}
}

void shuffle(int arr[], int length)
{
	for (int i = length - 1; i > 0; i--) {
		int j = std::rand() % i;
		int temp = arr[j];
		arr[j] = arr[i];
		arr[i] = temp;
	}
}
