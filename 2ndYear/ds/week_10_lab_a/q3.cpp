#include <iostream>
#include <queue>
using namespace std;
struct Node{
    char data;
    Node *lChild;
    Node *rChild;
    };

class BinaryTree{
public:
    Node *root;
    BinaryTree(){
        root = NULL;
        }
    Node* createTree(char *arr, int len, int i){
            if(arr[i] == 0 || i >= len) return NULL;
            Node *n1 = new Node;
            n1->data = arr[i];
            n1 -> lChild = createTree(arr,len,2*i + 1);
            n1 -> rChild = createTree(arr,len,2*i + 2);
            return n1;
        }

    // void displaylevelOrder(){
    //     queue <Node *> Q;
    //     Q.push(root);
    //     while(!Q.empty()){
    //         Node *temp = Q.front();
    //         cout << temp->data << " ";
    //         Q.pop();
    //         if(temp->lChild != NULL) Q.push(temp->lChild);
    //         if(temp->rChild != NULL) Q.push(temp->rChild);
    //     }
    //     }

    void displaylevelOrder(Node *root){
        queue <Node *> Q;
        Q.push(root);
        if(root != NULL){
            
        }
    }

    // void displaySpiralOrder(){
    //     queue <Node *> Q;
    //     Q.push(root);
    //     int count = 0;
    //     while(!Q.empty()){
    //         Node *temp = Q.front();
    //         cout << temp->data << " ";
    //         Q.pop();
    //         if(temp->lChild != NULL) Q.push(temp->lChild);
    //         if(temp->rChild != NULL) Q.push(temp->rChild);

    //     }
    //     }

    };


int main(){
    int len;
    cout << "Enter length of array : ";
    cin >> len;
    char *arr = new char[len];
    cout << "Enter array : ";
    for(int i = 0 ; i < len;i++){
        cin >> arr[i];
    }
    BinaryTree b1;
    b1.root = b1.createTree(arr, len, 0);
    cout << "Level order : ";
    b1.displaylevelOrder();
    cout << endl << "Spiral order : ";
    //b1.displaySpiralOrder();
    return 0;

    }
