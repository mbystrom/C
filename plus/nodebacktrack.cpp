#include <iostream>
#include <vector>

#define NODE_COUNT 20

using namespace std;

struct Point {
	Point () {
		x = 0;
		y = 0;
	}
	int x;
	int y;
};

struct Node {
	Node (Node* _parent) {
		pos = Point();
		parent = _parent;
	}
	Node () {
		pos = Point();
		parent = nullptr;
	}

	Node* parent;
	Point pos;
};

vector<Node> makeNodes () {
	Node current = Node();
	vector<Node> nodes;
	for (int i = 0; i < NODE_COUNT; i++) {
		Node* newNode = new Node(&current);
		current = newNode;
		nodes.push_back(current);
		delete newNode;
	}
	return nodes;
}

vector<Point> backtrack (Node* node) {
	vector<Point> points;
	points.push_back(node->pos);
	int loops = 0;
	while (node->parent != nullptr && node != nullptr) {
		node = node->parent;
		cout << "on loop #" << ++loops << endl;
		points.push_back(node->pos);
	}
	return points;
}

int main () {
	vector<Node> nodes = makeNodes();
	Node lastNode = nodes[nodes.size() - 1];
	vector<Point> track = backtrack(&lastNode);
	cout << "'nodes' is " << nodes.size() << " items" << endl;
	cout << "'track' is " << track.size() << " items" << endl;
	for (int i = 0; i < (long)track.size(); i++) {
		cout << &track[i] << endl;
	}
	cin.ignore();
}
