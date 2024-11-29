//Sebastian Alejandro Veilleux Amaya A01644977

#ifndef MYGRAPH_H
#define MYGRAPH_H
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class MyGraph{
    private:
        vector<vector<int>> matriz;
        //poner como privados los metodos adicionales
        bool isConnected();
    public:
        MyGraph(vector<vector<int>>& matriz);
        void loadGraph(vector<vector<int>>& matriz);
        bool isTree();
        void topologicalSort();
        bool bipartiteGraph();
};

#endif