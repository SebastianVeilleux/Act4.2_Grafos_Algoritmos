// Sebastian Alejandro Veilleux Amaya A01644977
#include <iostream>
#include "MyGraph.h"

using namespace std;


int main(){
    vector<vector<int>> matriz = {
    {0,0,1,0,0},
    {0,0,0,0,0},
    {0,1,0,1,0},
    {0,0,0,0,1},
    {0,0,0,0,0}
    };

    MyGraph grafo = MyGraph(matriz);
    cout<<"IsTree: "<<grafo.isTree();
    cout<<endl<<"Topological: ";
    grafo.topologicalSort();
    cout<<endl<<"bipartio: "<<grafo.bipartiteGraph();
}