#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    int bf;
    };

class BST{
public:
    Node *root;
    BST(){
        root = NULL;
    }
    Node * insertNode(Node *root , int x){
        if(root == NULL){
            Node *n1 = new Node;
            n1->data = x;
            n1->left = NULL;
            n1->right = NULL;
            if(this->root == NULL){
            this->root = n1;
        }
            return n1;
        }
        if(root->data > x){
            root->left = insertNode(root->left,x);
        }
         if(root->data <= x){
            root->right = insertNode(root->right,x);
        }
        return root;
        }

    int getRightMin(Node *root){
        Node *temp = root;
        while(temp->left != NULL) temp = temp->left;
        return temp->data;
        }

    Node *removeNode(Node *root, int val){

        if(root == NULL)

        return NULL;

        if(root->data < val)

        root->right = removeNode(root->right,val);

        else if(root->data > val)

        root->left = removeNode(root->left,val);

        else {

        if(root->left == NULL && root->right == NULL)

        {

        free(root);

        return NULL;

        }
        else if(root->left == NULL)

        {

        Node *temp = root->right;

        free(root);

        return temp;

        }

        else if(root->right == NULL)

        {

        Node *temp = root->left;

        free(root);

        return temp; }

        else {

        int rightMin = getRightMin(root->right);

        root->data = rightMin;

        root->right = removeNode(root->right,rightMin);

        }

        }

        return root;

        }


    void postorder(){
        stack <Node*> s1;
        stack <Node *> s2;
        s1.push(root);
        while(!s1.empty()){
            Node *temp = s1.top();
            s1.pop();
            if(temp->left)
                s1.push(temp->left);
            if(temp->right)
                s1.push(temp->right);
            s2.push(temp);
        }
        while(!s2.empty()){
            cout << s2.top()->data << " ";
            s2.pop();
        }
        }



      void displaylevel(){
        queue <Node *> Q;
        displaylevel(root,Q);
        }

    void displaylevel(Node *root,queue <Node *> Q){
        if(root == NULL) return;
        cout << root->data << " ";
        Q.push(root->left);
        Q.push(root->right);
        root = Q.front();
        Q.pop();
        displaylevel(root,Q);
        }
    };

int main(){
    BST b1;
    int x;
    for(int i = 1; i<= 5;i++){
        cin >> x;
        b1.insertNode(b1.root,x);
    }
    b1.removeNode(b1.root,3);
    b1.postorder();
    return 0;
    }
