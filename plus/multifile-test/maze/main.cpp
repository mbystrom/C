#include <iostream>
#include "maze.h"

int height = 20;
int width = 20;

int main()
{
	std::vector<std::vector<int>> grid;
	grid = GenerateMaze(width, height);

	PrintMaze(grid, height, width);

	std::cout << "press enter: ";
	std::cin.ignore();
}