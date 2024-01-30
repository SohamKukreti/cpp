#include <iostream>
using namespace std;
#include <queue>


struct Node{
    int data[2];
    Node *link;
    Node(int x, int w){
        data[0] = x;
        data[1] = w;
        link = NULL;
    }
};

class LinkedList{
public:
    Node *root;
    LinkedList(){
        root = NULL;
    }
    void addNode(int x, int w){
        Node *n1 = new Node(x,w);
        if(root == NULL) root = n1;
        else{
            Node *temp = root;
            while(temp->link!= NULL){
                temp = temp->link;
            }
            temp->link = n1;
        }
    }

    void display(){
        Node *temp = root;
        while(temp!=NULL){
            cout << " (" << char(temp->data[0] + 97) << ", " << temp->data[1] << ") ";
            temp = temp->link;
        }
    }

    

};


class AdjList{
public:
    int n;
    LinkedList *arr;
    
    AdjList(){
        arr = new LinkedList[100];
        n = 100;
    }

    AdjList(int x){
        n = x;
        arr = new LinkedList[x];
    }

    void addEdge(int u, int v, int w){
        arr[u].addNode(v,w);
        arr[v].addNode(u,w);
    }
    void displayList(){
        for(int i = 0;i<n;i++){
            if(arr[i].root != NULL){
                cout << char(i + 97) << " : ";
                arr[i].display();
                cout << endl;
            }
            
        }
    }
    void bfs(LinkedList *arr, bool *vis, int node,int *dist, int *prev){
        queue <int> Q;
        Q.push(node);
        vis[node] = true;
        dist[node] = 0;
        while(!Q.empty()){
            int n1 = Q.front();
            vis[n1] = true;
            cout << char(n1 + 97) << " ";
            Q.pop();
            Node *temp = arr[n1].root;
            while(temp!=NULL){
                if(vis[temp->data[0]] == false){
                    dist[temp->data[0]]+=dist[n1];
                    prev[temp->data[0]] = n1;
                    Q.push(temp->data[0]);

                    if(temp->data[0] == 7){
                        cout << "Found g : ";
                        cout << dist[temp->data[0]];
                        cout << endl;
                    }

                }
                temp = temp->link;
            }
        }
    }
    void BFS(){
        bool visited[100];
        int dist[100];
        int prev[100];
        for(int i = 0;i<100;i++){
            visited[i] = false;
            dist[i] = INT16_MAX;
            prev[i] = -1;
        }

        for(int i = 0 ; i < n;i++){
            if(arr[i].root != NULL && visited[i] == false){
                bfs(arr,visited,i,dist,prev);
            }
        }
    }

    void dfs(LinkedList *arr, bool *visited, int i){
        Node *temp = arr[i].root;
        cout << char(i + 97) << " ";
        visited[i] = true;
        while(temp != NULL){
            if(visited[temp->data[0]] == false){
                dfs(arr,visited,temp->data[0]);
            }
            temp = temp->link;
        }
    }

    void DFS(){
        bool visited[100];
        for(int i = 0;i<100;i++){
            visited[i] = false;
        }
        
        for(int i = 0;i<100;i++){
            if(arr[i].root != NULL && visited[i] == false) dfs(arr,visited,i);
        }
        
    }

};

int main(){
    int n;
    cout << "Enter number of edges : ";
    cin >> n;
    AdjList a1;
    char c1;
    char c2;
    int w;
    for(int i = 0; i < n;i++){
        cin >> c1;
        cin >> c2;
        cin >> w;
        int v = int(c1 - 97);
        int u = int(c2 - 97);
        a1.addEdge(u,v,w);
    }
    
    a1.displayList();
    cout << endl;
    a1.DFS();
    cout << endl;
    return 0;
}

