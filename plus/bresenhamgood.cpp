#include <curses.h> // neccessary for the line

#include <ctime>    // for randomized start and end points
#include <cstdlib>

int maxWidth = 30;
int maxHeight = 30;

int sign (int x) {
    if (x > 0) return 1;
    else if (x < 0) return -1;
    else return 0;
}

int Abs (int x) {
    if (x < 0) return -x;
    return x;
}

void hLine (int x0, int y0, int x1, int y1) {
    int deltaX = x1 - x0;
    int deltaY = y1 - y0;
    int yIncrement = 1;
    if (deltaY < 0) {
        yIncrement = -1;
        deltaY = -deltaY;
    }
    int error = 2 * deltaY - deltaX;
    int y = y0;
    for (int x = x0; x <= x1; x++) {
        mvwaddch(stdscr, y, x, '*');
        if (error > 0) {
            y += yIncrement;
            error -= 2*deltaX;
        }
        error += 2*deltaY;
    }
}

void vLine (int x0, int y0, int x1, int y1) {
    int deltaX = x1 - x0;
    int deltaY = y1 - y0;
    int xIncrement = 1;
    if (deltaX < 0) {
        xIncrement = -1;
        deltaX = -deltaX;
    }
    int error = 2 * deltaX - deltaY;
    int x = x0;
    for (int y = y0; y <= y1; y++) {
        mvwaddch(stdscr, y, x, '*');
        if (error > 0) {
            x += xIncrement;
            error -= 2*deltaY;
        }
        error += 2*deltaX;
    }
}

void line (int x0, int y0, int x1, int y1) {
    if (Abs(y1 - y0) < Abs(x1 - x0)) {
        if (x0 > x1) {
            hLine(x1, y1, x0, y0);
        } else {
            hLine(x0, y0, x1, y1);
        }
    } else {
        if (y0 > y1) {
            vLine(x1, y1, x0, y0);
        } else {
            vLine(x0, y0, x1, y1);
        }
    }
}

int main () {
    std::srand(std::time(0));

    int startX = std::rand() % maxWidth;
    int startY = std::rand() % maxHeight;

    int endX = std::rand() % maxWidth;
    int endY = std::rand() % maxHeight;

    initscr();

    line(startX, startY, endX, endY);
    wrefresh(stdscr);

    getch();
    endwin();
}
