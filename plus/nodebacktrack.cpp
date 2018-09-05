#include <iostream>
#include <vector>

#define NODE_COUNT 20

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
};

struct Node {
    Node (Point _pos, Node* _parent) {
        pos = _pos;
        parent = _parent;
    }
    Node (Point _pos) {
        pos = _pos;
        parent = nullptr;
    }

    Node* parent;
    Point pos;
};

vector<Node> makeNodes () {
    Node current = Node(Point());
    vector<Node> nodes;
    for (int i = 0; i < NODE_COUNT; i++) {
        Node newNode = Node(Point(), &current);
        nodes.push_back(newNode);
        current = newNode;
    }
    return nodes;
}

vector<Point> backtrack (Node* node) {
    vector<Point> points;
    points.push_back(node->pos);
    while (node->parent != nullptr) {
        node = node->parent;
        points.push_back(node->pos);
    }
    return points;
}

int main () {
    vector<Node> nodes = makeNodes();
    Node lastNode = nodes[nodes.size()-1];
    vector<Point> track = backtrack(&lastNode);
    for (int i = 0; i < track.size(); i++) {
        cout << &track[i] << endl;
    }
}
