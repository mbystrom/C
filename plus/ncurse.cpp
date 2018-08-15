#include <iostream>
#include <curses.h>

int main ()
{
    initscr();
    keypad(stdscr, true);
    noecho();
    while (true) {
        int ch = getch();
        std::cout << ch << std::endl;
    }
}

