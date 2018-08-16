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

void HorizontalLine (int startX, int startY, int endX, int endY)
{
    if (startX > endX) {
        int temp = startX;
        startX = endX;
        endX = temp;
    }

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
    for (int x = startX; x <= startX + deltaX; x++) {
        mvwaddch(stdscr, y, x, '*');
        error += deltaErr;
        if (error >= 0.5) {
            y += sign(deltaY);
            error -= 1.0;
        }
    }
}

void VerticalLine (int startX, int startY, int endX, int endY)
{
    if (startY > endY) {
        int temp = startY;
        startY = endY;
        endY = temp;
    }

    float deltaX = endX - startX;
    float deltaY = endY - startY;
    float deltaErr;
    if ((endX - startX) >= 0) {
        deltaErr = deltaX/deltaY;
    } else {
        deltaErr = -deltaX/deltaY;
    }
    float error = 0.0;

    int x = startX;
    for (int y = startY; y <= startY + deltaY; y++) {
        mvwaddch(stdscr, y, x, '*');
        error += deltaErr;
        if (error >= 0.5) {
            x += sign(deltaX);
            error -= 1.0;
        }
    }
}

void DrawLine (int startX, int startY, int endX, int endY)
{
    float deltaX = (endX - startX);
    float deltaY = (endY - startY);

    if (deltaX >= deltaY) HorizontalLine(startX, startY, endX, endY);
    else VerticalLine(startX, startY, endX, endY);
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
