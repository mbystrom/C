#include <curses.h>
#include <ctime>
#include <cstdlib>

int maxWidth = 30;
int maxHeight = 30;

int sign (float x) {
    int z;
    (x >= 0) ? z = 1 : z = -1;
    return z;
}

void DrawLine (int startX, int startY, int endX, int endY)
{
    if (startX > endX) {
        int temp = startX;
        startX = endX;
        endX = temp;
    }

    int xRange = endX - startX;
    
    float deltaX = (endX - startX);
    float deltaY = (endY - startY);
    float deltaErr;
    if ((endY - startY) >= 0) {
        deltaErr = deltaY / deltaX;
    } else {
        deltaErr = -deltaY / deltaX;
    }
    float error = 0.0;
    
    int y = startY;
    for (int x = startX; x < startX + xRange; x++) {
        mvwaddch(stdscr, y, x, '*');
        error += deltaErr;
        if (error >= 0.5) {
            y += sign(deltaY);
            error -= 1.0;
        }
    }
}


int main ()
{
    std::srand(std::time(0));

    int startX = std::rand() % maxWidth;
    int startY = std::rand() % maxHeight;

    int endX = std::rand() % maxWidth;
    int endY = std::rand() % maxHeight;

    initscr();
    
    DrawLine(startX, startY, endX, endY);
    wrefresh(stdscr);

    getch();
    endwin();
}
