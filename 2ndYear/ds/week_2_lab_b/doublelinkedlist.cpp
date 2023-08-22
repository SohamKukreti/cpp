#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *prev;
    Node *next;
};
class linkedlist{
public:
    Node *head;
    linkedlist(){
        head = NULL;
    }
    void insertNode(int x){
        Node *n1 = new Node;
        n1->data = x;
        n1-> next = NULL;
        n1->prev = NULL;
        if(head == NULL){
            head = n1;
        }
        else{
            Node *temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = n1;
            n1->prev = temp;
            n1->next = NULL;
        }
    }
    void display(){
        Node *temp = head;
        while(temp != NULL){
                cout << temp->data;
                temp = temp->next;
            }
    }

    void insertSpecific(Node *n1,int x){
        Node *temp = head;
        while(temp!=NULL){
            if(temp -> data == x){
                n1->next = temp->next;
                temp->next->prev = n1;
                temp->next = n1;
                n1->prev = temp;
            }
            temp = temp->next;
        }
    }

    void deleteLastNode(){
        Node *temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        Node *n1 = temp->prev;
        delete temp;
        n1->next = NULL;
    }
};
int main(){
    linkedlist l1;
    l1.insertNode(1);
    l1.insertNode(2);
    l1.insertNode(3);
    l1.insertNode(4);
    Node *n1 = new Node;
    n1->data = 0;
    l1.insertSpecific(n1,3);
    l1.deleteLastNode();
    l1.display();
    cout << endl;
    return 0;
}