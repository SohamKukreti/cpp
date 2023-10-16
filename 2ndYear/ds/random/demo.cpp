#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Node{
int data;
Node *lChild;
Node *rChild;
};

class BinaryTree{
public:
    Node *root;
    BinaryTree(){
        root = NULL;
    }
    Node * createTree(int *arr,int len, int i){
        if(i >= len || arr[i] == 0) return NULL;
            Node *n1= new Node;
            n1->data = arr[i];
            if(i == 0){
                root = n1;
            }
            n1->lChild = createTree(arr,len,2*i + 1);
            n1->rChild = createTree(arr,len,2*i + 2);
            return n1;
        }
    void displayPreorder(Node *root){
        cout << root->data << " ";
        if(root->lChild != NULL){
            displayPreorder(root->lChild);
        }
        if(root->rChild != NULL){
            displayPreorder(root->rChild);
        }
        }

    void postordernon(){
        stack <Node *> s1;
        stack <Node *> s2;
        s1.push(root);
        while(!s1.empty()){
            Node *temp = s1.top();
            s2.push(temp);
            s1.pop();
            if (temp->lChild) s1.push(temp->lChild);
            if (temp->rChild) s1.push(temp->rChild);
        }
        while(!s2.empty()){
            cout << s2.top()->data << " ";
            s2.pop();
        }
        }

    void preorderNonRecursive(){
        stack<Node *> s1;
        s1.push(root);
        while(!s1.empty()){
            Node *temp = s1.top();
            s1.pop();
            cout << temp -> data << " ";
            if(temp->rChild) s1.push(temp->rChild);
            if(temp->lChild) s1.push(temp->lChild);
        }
        }

    void inorderNonRecursive(){
        stack <Node *> s1;
        Node * temp = root;
        while(!s1.empty() || temp != NULL){
            while(temp != NULL){
                s1.push(temp);
                temp = temp->lChild;
            }
            temp = s1.top();
            cout << temp->data << " ";
            s1.pop();
            temp = temp->rChild;
        }
        }

    void displayLevelOrder(Node *root,queue<Node *> Q){
        if(root != NULL){
            cout << root->data<< " ";
            Q.push(root->lChild);
            Q.push(root->rChild);
            Node * temp = Q.front();
            Q.pop();
            displayLevelOrder(temp,Q);
        }

    }
    void displayLevelOrder(){
        queue <Node *> Q;
        displayLevelOrder(root,Q);
        }



    void deleteNode(int x){
        queue <Node *> Q;
        Q.push(root);
        while(!Q.empty()){
            Node *temp = Q.front();
            Q.pop();
            if(temp->data == x){
                Node *temp1 = temp;
                temp = root;
                while(temp->rChild != NULL){
                    temp = temp->rChild;
                }
                temp1->data = temp->data;
                delete temp;
                break;
            }
            if(temp->lChild){
                Q.push(temp->lChild);
            }
            if(temp->rChild){
                Q.push(temp->rChild);
            }
        }
    }


    void insertNode(int x){
        Node *n1 = new Node;
        n1->data = x;
        n1->lChild = NULL;
        n1->rChild = NULL;
        queue <Node *> Q;
        Q.push(root);
        while(!Q.empty()){
            Node *temp = Q.front();
            Q.pop();
            if(temp->lChild){
                Q.push(temp->lChild);
            }
            else{
                temp->lChild = n1;
                break;
            }
            if(temp->rChild){
                Q.push(temp->rChild);
            }
            else{
                temp->rChild = n1;
                break;
            }

        }
        }
};

int main(){
    int len;
    cout << "Enter length : ";
    cin >> len;
    int arr[] = {10, 11 , 9, 7 , 0 , 15 ,8};
    /*
    cout << "Enter array : ";
    for(int i = 0;i<len;i++){
        cin >> arr[i];
    }
    */
    BinaryTree b1;
    b1.createTree(arr,len,0);
    b1.insertNode(55);
    b1.displayLevelOrder();
    cout << endl;
    b1.displayPreorder(b1.root);
    cout  << endl;
    b1.preorderNonRecursive();
    cout << endl;
    b1.inorderNonRecursive();
    cout << endl;
    b1.postordernon();
    return 0;
    }
