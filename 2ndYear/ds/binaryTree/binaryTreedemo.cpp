#include <iostream>
#include <queue>
using namespace std;
struct Node{
    int data;
    Node *lChild;
    Node *rChild;
};

class binaryTree{
public:
    Node *root;
    binaryTree(){
        root = NULL;
    }

    Node* CreateTree(){
        Node *n1 = new Node;
        if(root == NULL){
            root = n1;
        }
        cout << "Enter data : ";
        cin >> n1->data;
        if(n1->data == -1) return NULL;
        n1->lChild = CreateTree();
        n1->rChild = CreateTree();
        return n1;
    }

    void findHeight(Node *root){
        
    }

    Node *arraytoTree(int *arr,int len, int i){
        if(i >= len || arr[i] == 0) return NULL;
        Node *n1 = new Node;
        n1 -> data = arr[i];
        if(i == 0){
            root = n1;
        }
        n1->lChild = arraytoTree(arr,len,2*i+1);
        n1->rChild = arraytoTree(arr,len,2*i+2);
        return n1;
    }

    void displayPreorder(Node *root){
        if(root != NULL){
            cout << root->data << " ";
            displayPreorder(root->lChild);
            displayPreorder(root->rChild);
        }
    }
    void displayLevelorder(){
        queue<Node *> Q;
        Q.push(root);
        while(!Q.empty()){
            Node * n1 = Q.front();
            if(n1 != NULL){
            cout << n1->data << " ";
            Q.pop();
            if(n1->lChild){
                Q.push(n1->lChild);
            }
             if(n1->rChild){
                Q.push(n1->rChild);
            }
            
            }
        }
    }
};

int main(){
    // int *arr;
    // int len;
    // cout << "Enter size : ";
    // cin >> len;
    // arr = new int[len];
    // cout << "Enter array : ";
    // for(int i = 0;i<len;i++){
    //     cin >> arr[i];
    // }
     binaryTree b1;
    // b1.arraytoTree(arr,len,0);
    b1.CreateTree();
    b1.displayPreorder(b1.root);
    cout << endl;
    b1.displayLevelorder();
    cout << endl;
    return 0;
}