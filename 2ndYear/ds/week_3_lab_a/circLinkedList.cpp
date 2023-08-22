#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *link;
};

class linkedlist{
public:
    Node *rear;
    linkedlist(){
        rear = NULL;
    }
    void addNode(int n){
        Node *n1 = new Node;
        n1->data = n;
        if(rear == NULL){
            rear = n1;
            n1->link = n1;
        }
        else{
            Node *temp = rear->link;
            do{
                temp = temp->link;
            }while(temp->link != rear->link);
            n1->link = rear->link;
            temp->link = n1;
            rear = n1;
        }
    }

    void deleteNode(int x){
        Node * curr = rear->link;
        Node * prev = rear;
        do{
            if(curr->data == x){
                prev-> link = curr->link;
                delete curr;
                break;
            }
            curr = curr->link;
            prev = prev->link;
        }while(curr != rear->link);
    }

    void display(){
        Node * temp = rear->link;
        do{
            cout << temp->data << " ";
            temp = temp->link;
        }while(temp != rear->link);
    }

};

int main(){
    linkedlist l1;
    l1.addNode(10);
    l1.addNode(20);
    l1.addNode(30);
    l1.addNode(40);
    l1.deleteNode(30);
    l1.display();
    cout << endl;
    return 0;
}