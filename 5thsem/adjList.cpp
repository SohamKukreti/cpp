#include <iostream>
#include <queue>
#include <vector>
#include <list>
using namespace std;

void bfs(vector <list<int>> &adjList, vector<bool> &visited, int vertices){
    queue <int> q;
    int startNode = 0;
    q.push(startNode);
    visited[startNode] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(auto it: adjList[node]){
            if(!visited[it]){
                visited[it] = true;
                q.push(it);
            }
            
        }
    }

}


void dfs(vector <list<int>> &adjList, vector<bool> &visited, int vertices, int node){
    visited[node] = true;
    cout << node << " ";
    for(auto it : adjList[node]){
        if(!visited[it]){
            dfs(adjList, visited, vertices, it);
        }
    }
}

int main(){
    int vertices;
    int edges;
    cout << "enter number of vertices: ";
    cin >> vertices;
    cout << "enter number of edges : ";
    cin >> edges;
    vector <list <int>> adjList(vertices, list <int>());
    int node1;
    int node2;
    for(int i = 0;i<edges;i++){
        cin >> node1;
        cin >> node2;
        adjList[node1].push_back(node2);
        adjList[node2].push_back(node1);
    }
    vector<bool> visited(vertices, false);
    dfs(adjList, visited, vertices, 0);
    cout << "worked here";
    cout << endl;
    return 0;
}