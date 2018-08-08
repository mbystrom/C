#include <iostream>
#include <vector>
#include "hello.h"
#include "math.h"

int height = 20;
int width = 20;

int main()
{
    int a = 5;
    int b = 9;

    int c = Sum(a, b);

    std::cout << c << std::endl;

    PRINT_F(12.3f);
    PRINT_I(14);

    std::vector<std::vector<int>> vec;
    for (int i = 0; i < height; i++) {
            vec.push_back(std::vector<int>());
            for (int j = 0; j < width; j++) {
            vec[i].push_back(0);
        }
    }

    vec[12][11] = 1;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            std::cout << vec[y][x];
        }
        std::cout << std::endl;
    }

    char t[10];
    std::cout << "press enter to continue: ";
    std::cin >> t;

    return 0;
}