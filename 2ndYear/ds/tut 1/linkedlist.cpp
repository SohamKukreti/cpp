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
    void insertNode(int x){
        if(head == NULL){
            Node *n1 = new Node;
            head = n1;
            head->data = x;
            head->link = NULL;
        }
        else{
            Node *n1 = new Node;
            n1->data = x;
            n1->link = head;
            head = n1;
        }
    }
    void display(){
        Node *temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp= temp->link;
        }
        cout << endl;
    }
    void deleteItem(int x){
        if(head == NULL){
            return;
        }

        if(head->data == x){
            Node * temp = head;
            head = head->link;
            delete temp;
            return;
        }

        Node *temp = head->link;
        Node *prev = head;

        
        
        while(temp != NULL){
            if(temp->data == x){
                prev->link = temp->link;
                delete temp;
                return;
            }
            temp= temp->link;
            prev = prev->link;
        }
        
        
    }
};

int main(){ 
    linkedlist l1;
    l1.insertNode(10);
    l1.insertNode(20);
    l1.insertNode(30);
    l1.deleteItem(10);
    l1.display();
    return 0;
}