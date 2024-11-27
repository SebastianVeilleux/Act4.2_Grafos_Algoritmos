//Sebastian Alejandro Veilleux Amaya A0163

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
        void DFS(int nodoActual, vector<bool>& estadoActual);
    public:
        MyGraph(vector<vector<int>>& matriz);
        void loadGraph(vector<vector<int>>& matriz);
        void DFS(int nodoI);
        void BFS(int nodoI);
        bool isTree();
        void topologicalSort();
        bool bipartiteGraph();
};

#endif