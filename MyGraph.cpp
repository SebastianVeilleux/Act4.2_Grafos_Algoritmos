#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adjMatrix;

bool isConnected(){
    int root = 0;
    vector<bool> visited(adjMatrix.size(), false);
    vector<int> stack;
    stack.push_back(root);
    visited[root] = true;

    while(!stack.empty()){
        int node = stack.back();
        stack.pop_back();
        for(int i = 0; i < adjMatrix.size(); i++){
            if(adjMatrix[node][i] && !visited[i]){
                stack.push_back(i);
                visited[i] = true;
            }
        }
    }

    for(int i = 0; i < visited.size(); i++){
        if(!visited[i]){
            return false;
        }
    }

    return true;
}

void loadGraph(vector<vector<int>> matrix){
    adjMatrix = matrix;
}

bool isTree(){
    // check if it has n-1 edges
    int edges = 0; 
    for(int i = 0; i < adjMatrix.size(); i++){
        for(int j = 0; j < adjMatrix.size(); j++){
            if(adjMatrix[i][j]){
                edges++;
            }
        }
    }

    if(edges != adjMatrix.size() - 1){
        return false;
    }

    // Check that node 0 (root) has no incoming edges
    for(int i = 0; i < adjMatrix.size(); i++){
        int incomingEdges = 0;
        if(adjMatrix[i][0]){
            return false;
        }
    }

    // Any other node has zero incoming edges
    for(int i = 0; i < adjMatrix.size(); i++){
        int incomingEdges = 0;
        for(int j = 1; j < adjMatrix.size(); j++){
            if(adjMatrix[j][i]){
                incomingEdges++;
            }
        }
        if(incomingEdges != 0){
            return false;
        }
    }

    if(!isConnected()){
        return false;
    }

    return true;
}

void topologicalSort(){
    queue<int> colaP; // cola nodos con grado de entrada 0
    queue<int> colaR; // respuesta
    // lista con grados de entrada de cada nodo;
    int size = adjMatrix.size();
    int inDegree[size];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(adjMatrix[i][j]){
                inDegree[j]++;
            }
        }
    }

    // llena nodos de entrada o
    for(int i = 0; i < size; i++){
        if(inDegree[i] == 0){
            colaP.push(i);
        }
    }

    while(!colaP.empty()){
        int V = colaP.front();
        colaP.pop();
        colaR.push(V);

        for(int W : adjMatrix[V]){
            inDegree[W]--;
            if(inDegree[W] == 0){
                colaP.push(W);
            }
        }

    }

    for(int i = 0; colaR.size(); i++){
        cout << colaR.front() << " ";
        colaR.pop();
    }

}

bool bipartiteGraph(vector<vector<int>> adjMatrix){
    // Algoritmo de amplitud
    vector<int> color(adjMatrix.size(), -1);
    queue<int> cola;
    cola.push(0);
    color[0] = 0;
    while(!cola.empty()){
        int node = cola.front();
        cola.pop();
        for(int i = 0; i < adjMatrix.size(); i++){
            if(adjMatrix[node][i]){
                if(color[i] == -1){
                    if(color[node] == 0){
                        color[i] = 1; 
                    }else{
                        color[i] = 0;
                    }
                }else if(color[i] == color[node]){
                    return false;
                }
            }
        }
    }
    
    return true;
}

int main(){

    return 0;
}