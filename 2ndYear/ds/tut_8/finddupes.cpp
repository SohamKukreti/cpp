#include <iostream>
using namespace std;


struct Node{
int data;
Node *link;
};

class linkedlist{
private:
    Node *head;
public:
    linkedlist(){
        head = NULL;
    }

    void SortedInsert(int x){
        Node *n1 = new Node;
        n1->data = x;
        n1->link = NULL;
        if(head == NULL){
            head = n1;
        }
        else{
            Node *temp = head;
            if(x < temp->data){
                n1->link = temp;
                head = n1;
                return;
            }
            while(temp->link != NULL){
                if(x <= temp->link->data){
                    n1->link = temp->link;
                    temp->link = n1;
                    return;
                }
                temp = temp->link;
            }
            temp->link = n1;
        }
        }

    void addNode(int x){
        Node *n1 = new Node;
        n1->data = x;
        n1->link = NULL;
        if(head == NULL){
            head = n1;
        }
        else{
            Node *temp = head;
            while(temp->link != NULL){
                temp = temp->link;
            }
            temp->link = n1;
        }
    }

    void display(){
        Node *temp = head;
        while(temp!=NULL){
            cout << temp->data << " ";
            temp = temp->link;
        }
    }
    void deleteNode(Node *n1){
        Node *curr = head->link;
        Node *prev = head;
        if(head == n1){
            delete prev;
            head = curr;
        }
        else{
            while(curr != NULL){
                if(curr == n1){
                    prev->link = curr->link;
                    delete curr;
                    break;
                }
                prev = curr;
                curr = curr->link;
            }
        }
    }

};

struct lNode{
    linkedlist data;
    lNode *link;
    };

class MultiList{
public:
    lNode *head;
    MultiList(){
    head = NULL;
    }
    void addList(linkedlist l1){
        lNode *l = new lNode;
        l->data = l1;
        l->link = NULL;
        if(head == NULL){
            head = l;
        }
        else{
            while
        }
        }

    };

class Matrix{
public:
    int r;
    int c;

    };

int main(){

    }
