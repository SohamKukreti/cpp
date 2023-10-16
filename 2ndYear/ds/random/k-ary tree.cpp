#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *children[3];

    Node(int val) {
        data = val;
        for (int i = 0; i < 3; i++) {
            children[i] = nullptr;  // Initialize child pointers to nullptr
        }
    }
};

void inorder(Node *root) {
    if (root == nullptr) return;

    inorder(root->children[0]); // Traverse left child
    inorder(root->children[1]); // Traverse middle child
    cout << root->data << " ";  // Print current node
    inorder(root->children[2]); // Traverse right child
}

void preorder(Node *root){
    if(root == NULL) return ;
    cout << root->data << " ";
    preorder(root->children[0]); // Traverse left child
    preorder(root->children[1]); // Traverse middle child
    preorder(root->children[2]); // Traverse right child
    }

void postorder(Node *root){
    if(root == NULL) return ;
    postorder(root->children[0]); // Traverse left child
    postorder(root->children[1]); // Traverse middle child
    postorder(root->children[2]); // Traverse right child
    cout << root->data << " ";
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
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    return 0;
}
