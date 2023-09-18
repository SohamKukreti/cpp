#include <iostream>
using namespace std;

struct Node{
int data;
Node *next;
Node *child;
};

class multilinkedlist{
public:
    Node *head;
    int col;
    int i;
    multilinkedlist(){
        i = 0;
        col = 3;
        head = NULL;
    }
    multilinkedlist(int col){
        this->col = col;
        i = 0;
        head = NULL;
    }
    void addNode(int x){
        Node *n1 = new Node();
        n1->data = x;
        n1->next = NULL;
        n1->child = NULL;
        if(head == NULL){
            head = n1;
            i++;

        }
        else{
            Node *tempRow = head;
            Node *tempCol = head;
            while(tempRow->child != NULL){
                tempRow = tempRow->child;
            }
            tempCol = tempRow;
            if(i<col){
                while(tempCol->next != NULL){
                    tempCol = tempCol->next;
                }
                tempCol->next = n1;
                i++;
            }
            else{
                i = i%3;
                tempRow->child = n1;
                i++;
            }

        }

    }

    void display(){
        Node *tempRow = head;
        Node *tempCol = head;
        while(tempRow != NULL){
            tempCol = tempRow;
            while(tempCol != NULL){
                cout << tempCol->data << " ";
                tempCol = tempCol->next;
            }
            cout << endl;
            cout << "| " << endl;

            tempRow = tempRow ->child;
        }
    }

    void InsertSpecific(int x, int y){
        Node *tempRow = head;   
        Node *tempCol = head;
        Node *n1 = new Node;
        n1->data = x;
        n1->next =NULL;
        n1->child = NULL;
        while(tempRow != NULL){
            tempCol = tempRow;
            while(tempCol != NULL){
                if(tempCol->data == y){
                    n1->next = tempCol->next;
                    tempCol->next = n1;
                }
                tempCol = tempCol->next;
            }
            tempRow = tempRow ->child;
        }
    }
    
    void flatten(){
        Node *tempRow = head;
        Node *tempCol = head;
        while(tempRow != NULL){
            tempCol = tempRow;
            while(tempCol != NULL){
                cout << tempCol->data << " "; 
                tempCol = tempCol->next;
            }
            tempRow = tempRow ->child;
        }
    }

    
};

int main(){
    multilinkedlist l1;
    for(int i = 0;i<9;i++){
        l1.addNode(i+1);
    }
    l1.InsertSpecific(15,5);
    l1.display();
    l1.flatten();
    return 0;
}