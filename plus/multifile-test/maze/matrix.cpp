#include <vector>

// Int version
std::vector<std::vector<int>> generate_matrix(int width, int height, int value)
{
	std::vector<std::vector<int>> vec;
	for (int y = 0; y < height; y++) {
		vec.push_back(std::vector<int>());
		for (int x = 0; x < width; x++) {
			vec[y].push_back(value);
		}
	}
	return vec;
}
