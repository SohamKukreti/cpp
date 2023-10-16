#include<iostream>

using namespace std;

class Node {

public:

int data;

Node *children[3];

Node(int val)

{

data = val;

}

};

void inorder(Node *root){
    if (root == NULL) return;
    for(int i = 0 ; i< 2;i++){
        inorder(root->children[i]);
    }
    cout << root->data;
    inorder(root->children[3])
    }

int main() {

Node* root = new Node(1);

root->children[0] = new Node(2);

root->children[1] = new Node(3);

root->children[2] = new Node(4);

root->children[0]->children[0] = new Node(5);

root->children[0]->children[1] = new Node(6);

root->children[0]->children[2] = new Node(7);

inorder(root);

return 0;

}
