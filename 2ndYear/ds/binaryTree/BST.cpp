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

    int findRightMin(Node *root){
        root = root->rChild;
        while(root->lChild != NULL){
            root = root->lChild;
        }
        return root->data;
    }



    Node *deleteNode(Node *root , int x){
        if(root == NULL) return NULL;

        if(root->data > x){
            root->lChild = deleteNode(root->lChild,x);
        }

        if(root->data < x){
            root->rChild = deleteNode(root->rChild,x);
        }

        else{
            if(root->lChild == NULL && root->rChild == NULL){
                root = NULL;
                return NULL;
            }
            else if(root->rChild == NULL){
                Node *temp = root->lChild;
                delete root;
                return temp;
            }
            else if(root->lChild == NULL){
                Node *temp = root->rChild;
                delete root;
                return temp;
            }
            else{
                int rMin = findRightMin(root);
                root->data = rMin;
                deleteNode(root->rChild,rMin);
            }
        }

        return root;

        }

    Node * insertNode(Node *root , int x){
        if(root == NULL){
            Node *n1 = new Node;
            n1->data = x;
            n1->lChild = NULL;
            n1->rChild = NULL;
            if(this->root == NULL){
            this->root = n1;
        }
            return n1;
        }
        if(root->data > x){
            root->lChild = insertNode(root->lChild,x);
        }
         if(root->data <=x){
            root->rChild = insertNode(root->rChild,x);
        }
        return root;
        /*

        to balance in avl:

        int bal = findHeight(leftsubtree) - findheihgt(rightsubtree);
        if(bal > 1 && x < root->left.data){
            return rightrotate(root)
        }
        if(bal > 1 && x > root->left.data){
            root->left = leftRotate(root->left);
            return rightrotate(root)
        }
        if(bal < -1 && root->right->data < x){
            return leftrotate(root)
        }
        if(bal < -1 && root->right->data > x){
            root->right = rightrotate(root->right)
            return leftrotate(root);
        }

        update balance factor of root and x
        return root

        */
        }

    Node *findSmallest(Node * root){
        if(root->lChild == NULL){
            return root;
        }
        if(root != NULL){
            findSmallest(root->lChild);
        }

        }

    Node *findLargest(){
        Node * temp = root;
        while(temp->rChild != NULL){
            temp = temp->rChild;
        }
        return temp;
        }

    Node *findNode(){

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
    binaryTree b1;
    while(true){
        int x;
        cout << "enter data : ";
        cin >> x;
        if(x < 0) break;
        b1.insertNode(b1.root,x);
    }
    //b1.deleteNode(b1.root,5);
    b1.displayPreorder(b1.root);
    cout << endl;
    b1.displayLevelorder();
    cout << endl;
    cout << b1.findLargest()->data;
    cout << b1.findSmallest(b1.root)->data;
    return 0;
}
