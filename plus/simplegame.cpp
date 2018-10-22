#include <iostream>
#include <curses.h>
#include <vector>

class Vec {
private:
public:
    Vec () {
        x = 0;
        y = 0;
    }
    Vec(int _x, int _y) {
        x = _x;
        y = _y;
    }

    int x;
    int y;

    Vec operator + (Vec other) {
        int X = this->x + other.x;
        int Y = this->y + other.y;
        return Vec(X,Y);
    }
};

class Tile {
private:
public:
    Tile () {
        pos = Vec(0,0);
        isFloor = false;
        hasActor = false;
    }
    Tile(int _x, int _y) {
        pos = Vec(_x, _y);
        isFloor = false;
        hasActor = false;
    }
    Tile(int _x, int _y, bool f) {
        pos = Vec(_x, _y);
        isFloor = f;
        hasActor = false;
    }

    Vec pos;
    bool isFloor;
    bool hasActor;
};

typedef std::vector<std::vector<Tile>> matrix;

class Actor {
private:
public:
    Actor(int x, int y, bool p) {
        pos = Vec(x,y);
        isPlayer = p;
    }

    Vec pos;
    bool isPlayer;

    void move (Vec dir, matrix* grid) {
        Vec newPos = this->pos + dir;
        if ((*grid)[newPos.y][newPos.x].isFloor &&
                !(*grid)[newPos.y][newPos.x].hasActor) {
            (*grid)[pos.y][pos.x].hasActor = false;
            this->pos = newPos;
            (*grid)[pos.y][pos.x].hasActor = true;
        }
    }
};

matrix TestGrid () {
    matrix vex;
    for (int y = 0; y < 20; y++) {
        vex.push_back(std::vector<Tile>());
        for (int x = 0; x < 40; x++) {
            Tile tile = Tile(x,y);
            if (x == 0 || x >= 39 || y == 0 || y >= 19) {
                tile.isFloor = false;
            } else {
                tile.isFloor = true;
            }
            vex[y].push_back(tile);
        }
    }
    return vex;
}

std::vector<Actor> MakeActors (matrix* grid) {
    std::vector<Actor> actors;
    actors.push_back(Actor(12,12,true));
    (*grid)[12][12].hasActor = true;
    return actors;
}

Vec Input (Actor* actor) {
    int key = getch();
    Vec pos = actor->pos;
    if (key == 259) {
        return Vec(0,-1);
    } else if (key == 258) {
        return Vec(0,1);
    } else if (key == 261) {
        return Vec(1,0);
    } else if (key == 260) {
        return Vec(-1,0);
    } else {
        return Vec(0,0);
    }
}

void MoveActors (std::vector<Actor>* actors, matrix* grid) {
    for(Actor& actor : *actors) {
        if (actor.isPlayer) {
            actor.move(Input(&actor), grid);
        }
    }
}

void Render (std::vector<Actor>* actors, matrix* grid) {
    for (Actor actor : *actors) {
        mvwaddch(stdscr, actor.pos.y, actor.pos.x, '@');
    }
    for (std::vector<Tile> row : *grid) {
        for (Tile tile : row) {
            char ch;
            (tile.isFloor) ? ch = '.' : ch = '#';
            if (!tile.hasActor) {
                mvwaddch(stdscr, tile.pos.y, tile.pos.x, ch);
            }
        }
    }
}

void GameLoop (std::vector<Actor>* actors, matrix* grid) {
    Render(actors, grid);
    for (;;) {
        MoveActors(actors, grid);
        Render(actors, grid);
    }
}

int main () {
    initscr();
    noecho();
    keypad(stdscr, true);
    matrix grid = TestGrid();
    std::vector<Actor> actors = MakeActors(&grid);
    GameLoop(&actors, &grid);
    endwin();
}
