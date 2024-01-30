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

void createMST(adjList a1){
    int n = a1.n;
    int *keys = new int[n];
    bool *mst = new bool[n];
    int *parent = new int[n];
    for(int i = 0;i<n;i++){
        keys[i] = INT8_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    keys[0] = 0;

    for(int i = 1;i<n;i++){
        int min = INT8_MAX;
        int min_ind = -1;
        for(int j = 0;j<n;j++){
            if(keys[j] < min && mst[j] == false){
                min = keys[j];
                min_ind = j;
            }
        }
        //cout << "minimum index is : " << min_ind << endl;
        mst[min_ind] = true;


        Node *temp = a1.arr[min_ind].root;
        while(temp != NULL){
            if(temp != NULL){
            int i = temp->data[0];
            int w = temp->data[1];
            if(w < keys[i] && mst[i] == false){
                keys[i] = w;
                parent[i] = min_ind;
            }
            }
            temp = temp->link;
            
        }


    }

    for(int i = 0; i < n ;i++){
        //cout << " i is " <<  i << " and parent is  ";
        cout << parent[i] << " ";
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
    for(int i = 0; i < n;i++){
        cin >> v;
        cin >> u;
        cin >> w;
        a1.addEdge(u,v,w);
    }
    a1.displayList();
    createMST(a1);
    cout << endl;
    return 0;
}