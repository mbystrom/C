#include <iostream>
#include <vector>
#include <algorithm>

#define HEIGHT 10
#define WIDTH 20

using namespace std;

struct Point {
	Point () {
		x = 0;
		y = 0;
	}
	Point (int _x, int _y) {
		x = _x;
		y = _y;
	}

	int x;
	int y;

	Point operator + (const Point& other) {
		int X = this->x + other.x;
		int Y = this->y + other.y;
		return Point(X, Y);
	}
	bool operator == (const Point& other) {
		return (this->x == other.x && this->y == other.y);
	}
	bool operator != (const Point& other) {
		return !(this->x == other.x && this->y == other.y);
	}
};

struct Directions {
	Point N = Point(0, -1);
	Point S = Point(0, 1);
	Point E = Point(1, 0);
	Point W = Point(1, 0);
	Point NE = Point(1, -1);
	Point NW = Point(-1, -1);
	Point SE = Point(1, 1);
	Point SW = Point(-1, 1);

	Point All[8] = { N, NE, E, SE, S, SW, W, NW };
	Point Cardinal[4] = { N, S, E, W };
	Point Diagonal[4] = { NW, NE, SW, SE };
};

int grid[HEIGHT][WIDTH] = {
	{ 0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0 },
	{ 0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0 },
	{ 0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0 },
	{ 0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0 },
	{ 0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0 },
	{ 0,0,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1 },
	{ 0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0 }
};

bool isOut (Point check) {
	if (check.x < 0 || check.y < 0) return true;
	if (check.x >= WIDTH || check.y >= HEIGHT) return true;
	return false;
}

vector<Point> getNeighbors (Point point, int grid[HEIGHT][WIDTH]) {
	Directions dirs;
	vector<Point> neighbors;
	for (const Point& dir : dirs.All) {
		Point newPoint = point + dir;
		if (!isOut(newPoint) && grid[newPoint.y][newPoint.x] == 0) {
			neighbors.push_back(newPoint);
		}
	}
	return neighbors;
}

int getDistance (Point p1, Point p2) {
	int dY = abs(p2.y - p1.y);
	int dX = abs(p2.x - p1.x);
	if (dY > dX) return dY;
	else return dX;
}

bool vecContains (vector<Point> vec, Point point) {
	if (find(vec.begin(), vec.end(), point) != vec.end()) return true;
	else return false;
}

vector<Point> greedySearch (Point start, Point goal, int grid[HEIGHT][WIDTH]) {
	Directions dirs;
	
	Point currentPoint = start;
	vector<Point> path;
	path.push_back(start);

	while (currentPoint != goal) {
		currentPoint = path.back();
		vector<Point> neighbors = getNeighbors(currentPoint, grid);
		int minCost = 10*getDistance(currentPoint, goal);
		Point bestPoint = currentPoint;
		for (Point& neighbor : neighbors) {
			if (isOut(neighbor)) continue;
			int cost = getDistance(neighbor, goal);
			if (cost <= minCost && !vecContains(path, neighbor)) {
				bestPoint = neighbor;
				minCost = cost;
			}
		}
		path.push_back(bestPoint);
	}

	return path;
}

void PrintGrid (int grid[HEIGHT][WIDTH]) {
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			cout << grid[y][x];
		}
		cout << endl;
	}
}

int main () {
	Point start = Point(0, 0);
	Point goal = Point(17, 4);
	vector<Point> path = greedySearch(start, goal, grid);

	for (Point point : path) {
		grid[point.y][point.x] = 8;
	}
	PrintGrid(grid);
}