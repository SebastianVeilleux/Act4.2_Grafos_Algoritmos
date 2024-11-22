#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adjMatrix;

void loadGraph(vector<vector<int>> matrix){
    adjMatrix = matrix;
}

bool isTree(){

    // Root node has zero incoming edges, which is zero and there shouldn't be any other node with zero incoming edges
    for(int i = 0; i < adjMatrix.size(); i++){
        int zeroIncomingEdges = 0;
        for(int j = 0; j < adjMatrix.size(); j++){
        
            if(adjMatrix[i][j] == 1){
                zeroIncomingEdges++;
            }

            if(zeroIncomingEdges > 1){
                return false;
            }
        }
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