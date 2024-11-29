// Sebastian Alejandro Veilleux Amaya A01644977
#include <iostream>
#include "MyGraph.cpp"
#include "MyGraph.h"

using namespace std;


void testIsTree() {
    vector<vector<int>> matrix = {
        {0, 1, 0, 0},
        {1, 0, 1, 1},
        {0, 1, 0, 1},
        {0, 1, 1, 0}
    };
    MyGraph graph(matrix);
    cout << "isTree: " << (graph.isTree() ? "True" : "False") << endl;
}

void testTopologicalSort() {
    vector<vector<int>> matrix = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };
    MyGraph graph(matrix);
    cout << "Topological Sort: ";
    graph.topologicalSort();
    cout << endl;
}

void testBipartiteGraph() {
    vector<vector<int>> matrix = {
        {0, 1, 0, 0},
        {1, 0, 1, 1},
        {0, 1, 0, 1},
        {0, 1, 1, 0}
    };
    MyGraph graph(matrix);
    cout << "bipartiteGraph: " << (graph.bipartiteGraph() ? "True" : "False") << endl;
}

int main() {
    testIsTree();
    testTopologicalSort();
    testBipartiteGraph();
    return 0;
}