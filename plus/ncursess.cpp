#include <iostream>
#include <curses.h>

int main ()
{
    initscr();
    keypad(stdscr, true);
    while (true) {
        int x = getch();
        mvwaddch(stdscr, 1, 1, x);
        wrefresh(stdscr);
    }
}

