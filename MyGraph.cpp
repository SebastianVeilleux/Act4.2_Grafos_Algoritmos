#include <iostream>
#include <vector>

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
    
}

bool bipartiteGraph(vector<vector<int>>){
    return true;
}

int main(){

    return 0;
}