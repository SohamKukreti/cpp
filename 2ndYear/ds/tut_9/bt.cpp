#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Node{
    char data;
    Node *left;
    Node *right;
    };

class BinaryTree{
public:
    Node * root;
    BinaryTree(){
        root = NULL;
        }
    Node *CreateTree(char *arr,int len , int i){
        if(i > len || arr[i] == '0') return NULL;
        Node *n1 = new Node;
        n1->data = arr[i];
        if(i == 0) root = n1;
        n1->left = CreateTree(arr,len ,2 * i + 1);
        n1->right = CreateTree(arr,len, 2 * i + 2);
        return n1;
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

    int height(Node *root){
        if(root == NULL) return 0;
        int lHeight = height(root->left);
        int rHeight = height(root->right);
        if(lHeight >= rHeight) return lHeight + 1;
        else return rHeight + 1;
        }

    void countNodes(){
         stack <Node *> s1;
         Node *temp = root;
         int ncnt = 0;
         while(!s1.empty() || temp != NULL){
             while(temp != NULL){
                s1.push(temp);
                temp = temp->left;
             }
             temp = s1.top();
             s1.pop();
             ncnt++;
             temp = temp->right;
        }
        cout << "Node COunt : "<< ncnt << endl;
        }

    //preorder non recursive traversal to count leaves
    void leafCount(){
        stack <Node *> s1;
        s1.push(root);
        int leaf = 0;
        while(!s1.empty()){
            Node *temp = s1.top();
            s1.pop();
            if(temp->right) s1.push(temp->right);
            if(temp -> left) s1.push(temp->left);
            if(!(temp->right || temp->left)) leaf++;
        }
        cout << "NUmbero f leaves : " << leaf;
        }

    };

int main(){
    BinaryTree b1;
    b1.CreateTree("abcdefghi",8,0);
    b1.displaylevel();
    cout << endl;
    cout << b1.height(b1.root) << endl;
    b1.leafCount();
    cout << endl;
    b1.countNodes();
    return 0;
    }
