#include <iostream>
using namespace std;
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
            cout << " (" << temp->data[0] << ", " << temp->data[1] << ") ";
            temp = temp->link;
        }
    }

    
};

class adjList{
public:
    LinkedList *arr;
    int n;

    adjList(int x){
        arr = new LinkedList[x];
        n = x;
    }

    void addEdge(int u,int v, int w){
        arr[u].addNode(v,w);
        arr[v].addNode(u,w);
    }

    void displayList(){
        for(int i = 0;i<n;i++){
            if(arr[i].root!=NULL){
                cout << i << " : ";
                arr[i].display();
                cout << endl;
            }
        }
    }

};

void makeSet(int *parent,int *rank, int n){
    for(int i = 0;i< n;i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int findparent(int *parent, int node){
    if(parent[node] == node) return node;
    return parent[node] = findparent(parent,parent[node]);
}

void unionSet(int u,int v,int *parent, int *rank){
    u = findparent(parent,u);
    v = findparent(parent,v);
    
    if(rank[u] < rank[v]){
        parent[u] = v;
    }
    else if(rank[v] < rank[u]) parent[v] = u;
    else{
        parent[v] = u;
        rank[u]++;

    }
}

int main(){
     int v;
    int u;
    cout << "Enter number of edges : ";
    cin >> u;
    cout << "Enter number of vertices : ";
    cin >> v;
    int n = u;
    adjList a1(v);
    int w;
    int *parent = new int[v];
    int *rank = new int[v];
    makeSet(parent,rank, v);
    int **kArr = new int*[v];
    for(int i = 0;i< n;i++){
        kArr[i] = new int[3];
    }

    for(int i = 0; i < n;i++){
        cin >> v;
        cin >> u;
        cin >> w;
        kArr[i][0] = v;
        kArr[i][1] = u;
        kArr[i][2] = w;
        a1.addEdge(u,v,w);
    }

    for(int i = 0;i<a1.n;i++){
        for(int j = 0;j<a1.n;j++){
            if(kArr[j][2] > kArr[j + 1][2]){
                int *temp = kArr[j + 1];
                kArr[j + 1] = kArr[j];
                kArr[j] = temp;
            }
        }
    }
    int minWeight = 0;
    for(int i = 0;i< n;i++){
        int u = findparent(parent,kArr[i][0]);
        int v = findparent(parent,kArr[i][1]);
        int w = kArr[i][2];

        if(u != v){
            minWeight += w;
            unionSet(u,v,parent,rank);
        }
    }
    a1.displayList();
    cout << endl;
    cout << minWeight << endl;
}