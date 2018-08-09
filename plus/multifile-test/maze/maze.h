#ifndef MAZE_H
#define MAZE_H

#include <vector>
std::vector<std::vector<int>> GenerateMaze(int height, int width);
void PrintMaze(std::vector<std::vector<int>> grid, int height, int width);

#endif