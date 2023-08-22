#include <iostream>
using namespace std;

struct Node{
int data;
Node *link;
};

class circularlinkedlist{
private:
    Node *rear;
public:
    circularlinkedlist(){
        rear = NULL;

    }

    void addNode(int data){
        Node *n1 = new Node;
        if(rear == NULL){
            rear = n1;
            rear->link = rear;
        }
        else{
            Node *temp = rear->link;
            rear->link = n1;
            n1->link = temp;
        }
    }

    void display(){
        Node *temp2 = rear->link;
        do{ 
            cout << temp2->data << " ";
            temp2 = temp2->link;
        }while(temp2 != rear->link);

    }
    void splitList(){
        Node *temp = rear->link;
        Node *fasttemp = rear->link;
        circularlinkedlist c1;
        circularlinkedlist c2;
        do{ 
            fasttemp = fasttemp->link;
            fasttemp = fasttemp->link;
            temp = temp->link;
            c1.addNode(temp->data);
        }while(fasttemp != rear->link);
        Node *temp2 = temp->link;
        do{ 
            c2.addNode(temp2->data);
            temp2 = temp2->link;
        }while(temp2 != rear->link);

        c1.display();
        cout << endl;
        c2.display();

        

    }
};


int main(){
    circularlinkedlist c1;
    for(int i  = 1;i<=5 ;i++){
        c1.addNode(i);
    }
    c1.display();
    cout << endl;
    c1.splitList();
    return 0;
}