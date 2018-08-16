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
    float deltaX = (endX - startX);
    float deltaY = (endY - startY);

    bool horizontal;
    (deltaX >= deltaY) ? horizontal = true : horizontal = false;

    float deltaErr;
    float error = 0.0;
    if (horizontal) {
        if ((endY - startY) >= 0) {
        deltaErr = deltaY / deltaX;
        } else {
            deltaErr = -deltaY / deltaX;
        }
    }
    else {
        if ((endX - startX) >= 0) {
        deltaErr = deltaX/deltaY;
        } else {
            deltaErr = -deltaX/deltaY;
        }
    }

    int x = startX;
    int y = startY;

    while (true) {
        if (horizontal) {
            if (x >= startX + deltaX) break;
            x++;
        }
        else {
            if (y >= startY + deltaY) break;
            y++;
        }
        mvwaddch(stdscr, y, x, '*');
        error += deltaErr;

        if (error > 0.5) {
            if (horizontal) y += sign(deltaY);
            else x += sign(deltaX);
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
