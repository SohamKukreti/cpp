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
    void addNode(int d){
            Node *n1 = new Node;
            Node *curr = head;
            if(head == NULL){
                head = n1;
                n1->data = d;
                n1->link = NULL;
            }

            else{
                while(curr->link != NULL){
                    curr = curr->link;
                }
                curr->link = n1;
                n1->data = d;
                n1->link = NULL;
            }

        }

    void insertAtBeg(int d){
        Node *n1 = new Node;
        n1->data = d;
        n1->link = head;
        head = n1;
        }

    void display(){
        Node *temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp= temp->link;
        }
        cout << endl;
    }

    void bubbleSort(){
        Node *temp = head;
        while(temp->link!= NULL){
            Node * temp1 = temp;
            while(temp1->link != NULL){

                if(temp1->data > temp1->link->data){
                    Node *temp3 = new Node;
                    temp3->data = temp1->data;
                    temp1->data = temp1->link->data;
                    temp1->link->data = temp3->data ;
                }
                temp1 = temp1->link;
            }
            temp = temp->link;
        }
        }

    ~linkedlist(){
        Node *curr = head->link;;
        Node *prev = head;
        while(curr!=NULL){
            delete prev;
            prev = curr;
            curr = curr ->link;
        }
    }

};
int main(){
    int n;
    cout << "Enter a number : ";
    cin >> n;
    linkedlist l1;
    while(n != 0){
        int rem = n%10;
        l1.insertAtBeg(rem);
        n = n/10;
    }
    l1.display();
    cout << endl << "Sorted list " << endl;
    l1.bubbleSort();
    l1.display();
    return 0;
}
