#include <vector>
#include <iostream>

std::vector<std::vector<int>> generate_matrix (int height, int width, int value)
{
    std::vector<std::vector<int>> vec;
    for (int i = 0; i < height; i++) {
        vec.push_back(std::vector<int>());
        for (int j = 0; j < width; j++) {
            vec[i].push_back(value);
        }
    }
    
    return vec;
}

void print_matrix(std::vector<std::vector<int>> grid)
{
	for (std::vector<int> row : grid) {
		for (int i : row) {
			std::cout << i;
		}
		std::cout << std::endl;
	}
}