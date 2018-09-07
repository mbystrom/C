#include <iostream>
#include <vector>
#include <algorithm>

#define WIDTH 20
#define HEIGHT 10

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

struct Node {
	Node (Point _pos, Node* _parent) {
		pos = _pos;
		parent = _parent;
		g = 0;
		f = 0;
	}
	Node (Point _pos) {
		pos = _pos;
		parent = nullptr;
		g = 0;
		f = 0;
	}
	Node (const Node& copy) {
		pos = copy.pos;
		if (copy.parent == nullptr) {
			parent = nullptr;
		} else {
			parent = new Node(Point());
			*parent = *copy.parent;
		}
		g = copy.g;
		f = copy.f;
	}
	~Node () {
		parent = nullptr;
	}

	Node* parent;
	Point pos;
	int g;
	int f;

	bool operator == (const Node& other) {
		return (this->pos == other.pos);
	}
	bool operator != (const Node& other) {
		return !(this->pos == other.pos);
	}
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

int heuristic (Node node1, Node node2) {
	int dX = abs(node2.pos.x - node1.pos.x);
	int dY = abs(node2.pos.y - node1.pos.y);
	if (dX > dY) return dX;
	return dY;
}

bool isOut (Point pos) {
	if (pos.x < 0 || pos.x >= WIDTH) return true;
	if (pos.y < 0 || pos.y >= HEIGHT) return true;
	return false;
}

vector<Node> getNeighbors (Node node, int grid[HEIGHT][WIDTH]) {
	vector<Node> neighbors;
	Directions directions;
	for (Point direction : directions.All) {
		Point newPos = node.pos + direction;
		if (isOut(newPos) || grid[newPos.y][newPos.x] != 0) continue;
		Node newNode = Node(newPos);
		newNode.parent = &node;
		if (find(begin(directions.Diagonal), end(directions.Diagonal), direction) != end(directions.Diagonal)) {
			newNode.g = node.g + 1;
		} else {
			newNode.g = node.g + 1;
		}
		neighbors.push_back(newNode);
	}
	return neighbors;
}

vector<Point> constructPath (Node* node) {
	vector<Point> path;
	path.push_back(node->pos);
	int loop = 0;
	while (node->parent != NULL) {
		Node* newNode = node->parent;
		path.push_back(newNode->pos);
		node = newNode;
		if (loop++ >= 2500) break;
	}
	reverse(path.begin(), path.end());
	return path;
}

vector<Point> aStar (Node start, Node goal, int grid[HEIGHT][WIDTH]) {
	start.g = 0;
	start.f = start.g + heuristic(start, goal);

	vector<Node> openList;
	vector<Node> closedList;
	openList.push_back(start);

	while (openList.size() > 0) {
		Node current = openList[0];
		int index = 0;
		for (int i = 0; i < (long)openList.size(); i++) {
			if (openList[i].f < current.f) {
				current = openList[i];
				index = i;
			}
		}
		if (current == goal) {
			return constructPath(&current);
		}
		openList.erase(openList.begin() + index);
		closedList.push_back(current);

		vector<Node> neighbors = getNeighbors(current, grid);
		for (Node neighbor : neighbors) {
			if (find(closedList.begin(), closedList.end(), neighbor) != closedList.end()) {
				continue;
			}
			neighbor.f = neighbor.g + heuristic(neighbor, goal);
			if (find(openList.begin(), openList.end(), neighbor) != openList.end()) {
				for (Node openNeighbor : openList) {
					if (neighbor.pos == openNeighbor.pos) {
						if (neighbor.g < openNeighbor.g) {
							openNeighbor.g = neighbor.g;
							openNeighbor.parent = neighbor.parent;
						}
					}
				}
			} else {
				openList.push_back(neighbor);
			}
		}
	}
	return vector<Point>();
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
	Point startPos = Point(0, 0);
	Point endPos = Point(10, 7);
	Node startNode = (startPos);
	Node endNode = (endPos);

	vector<Point> path = aStar(startNode, endNode, grid);
	for (Point point : path) {
		grid[point.y][point.x] = 8;
	}
	PrintGrid(grid);
}