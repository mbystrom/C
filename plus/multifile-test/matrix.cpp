#include <vector>

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