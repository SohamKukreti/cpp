#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *nextCol;
    Node *nextRow;
};

class rowColList{
public:
    Node *head;
    rowColList(){
        head = NULL;
        }
    void addNode(int x){
        Node * n1 = new Node;
        n1->data = x;
        n1->nextCol = NULL;
        n1->nextRow = NULL;
        if(head == NULL){
            head = n1;
        }
        else{
            Node *row = head;
            Node *col = head;
            while(row->nextRow != NULL){
                row = row->nextRow;
            }
            while(col->nextCol != NULL){
                col = col->nextCol;
            }
            col->nextCol = n1;
        }
    }

    void display(){
        Node *row = head;
        Node *col = head;
        while(row != NULL){
            col = row;
            while(col != NULL){
                cout << col->data;
                col = col->nextCol;
            }
            row = row->nextRow;
        }

        }
};
int main(){
    rowColList l1;
    for(int i = 0;i<5;i++){
         l1.addNode(i);
    }
    l1.display();

    return 0;
    }
