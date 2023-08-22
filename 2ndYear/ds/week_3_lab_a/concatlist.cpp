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
    friend linkedlist concat(linkedlist l1, linkedlist l2);

};

linkedlist concat(linkedlist l1, linkedlist l2){
    linkedlist l3;
    Node *n1 = (l1.rear)->link;
    Node *n2 = (l2.rear)->link;
    do{
       l3.addNode(n1->data);
       n1 = n1->link;
    }while(n1 != (l1.rear)->link);
    do{
       l3.addNode(n2->data);
       n2 = n2->link;
    }while(n2 != (l2.rear)->link);
    return l3;

}


int main(){
    linkedlist l1;
    linkedlist l2;
    for(int i = 1 ;i<=5;i++){
        l1.addNode(i);
        l2.addNode(i*10);
    }
    linkedlist l3 = concat(l1,l2);
    l1.display();
    cout << endl;
    l2.display();
    cout << endl;
    l3.display();
    cout << endl;
    return 0;
}