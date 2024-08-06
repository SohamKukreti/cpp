#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &adjMatrix, vector <bool> &visited, int vertices){
    queue<int> q;
    int startNode = 0;
    visited[startNode] = true;
    q.push(startNode);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int i = 0;i<vertices;i++){
            if(adjMatrix[node][i] && !visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

void dfs(vector<vector<int>> &adjMatrix, vector <bool> &visited, int vertices, int node){
    cout << node << " ";
    visited[node] = true;
    for(int i = 0;i<vertices;i++){
        if(adjMatrix[node][i] && !visited[i]){
            dfs(adjMatrix, visited, vertices, i);
        }
    }
}

int main(){
    int vertices;
    cout << "enter number of vertices : ";
    cin >> vertices;
        vector <vector<int>> adjMatrix(vertices, vector<int>(vertices, 0));
    for(int i = 0;i<vertices;i++){
        for(int j = 0;j<vertices;j++){
            cin >> adjMatrix[i][j];
        }
    }
    cout << endl;
    vector<bool> visited(vertices, false);
    dfs(adjMatrix, visited, vertices, 0);
    return 0;
}