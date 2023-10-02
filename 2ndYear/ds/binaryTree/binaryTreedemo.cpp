#include <iostream>
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

    void arraytoTree(int *arr,int len){
        Node **arr1 = new Node*[len];
        for(int i = 0;i<len;i++){
            arr1[i] = new Node;
        }
        for(int i = 0;i<len;i++){
            arr1[i] -> data = arr[i];
            if(i == 0){
                root = arr1[i];
                arr1[i]->lChild = arr1[2 * i + 1];
                arr1[i]->rChild = arr1[2 * i + 2];
            }
            else{
                arr1[i]->rChild = arr1[2*i + 1];
                arr1[i]->lChild = arr1[2*i + 2];
            }
        }
    }
    void displayPreorder(Node *root){
        if(root != NULL){
            cout << root->data;
            displayPreorder(root->lChild);
            displayPreorder(root->rChild);
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
    // b1.arraytoTree(arr,len);
    // cout << "hey" << endl;
    b1.displayPreorder(b1.root);
    cout << endl;
    return 0;
}