#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
    };

class LinkedList{
    private:
        node *head;
        node *tail;
    public:
        LinkedList(){
            head = NULL;
        }
        addNode(int data){
            node *tmp = new node;
            tmp->data = data;
            tmp->next = NULL;
            if(head == NULL){
                head = tmp;
                tail = tmp;
                }
            else{
                tail->next = tmp;
                tail = tail->next;
                }
            }
        display(){
            while(head != NULL){
                cout << head->data << " ";
                head = head->next;
            }
            }



    };

int main(){
    LinkedList l1;
    l1.addNode(1);
    l1.addNode(2);
    l1.addNode(3);
    l1.addNode(4);
    l1.display();
    }

/*
#include <iostream>
using namespace std;
class node{
    public:
        int data;
        node *next;
        node(){
            data = 0;
            next = NULL;
            }
        node(int data){
            this->data = data;
            next = NULL;
            }
    };

    void insertAtTail(node *head,int data){
        while(head->next != NULL){
            head = head->next;
        }
        node *n1 = new node(data);
        head->next = n1;
        }
    void displayLinkedList(node *head){
        while(head != NULL){
            cout << head->data << " ";
            head = head->next;
            }
        }


int main(){
    node *root = new node(1);
    insertAtTail(root,2);
    insertAtTail(root,3);
    insertAtTail(root,4);
    displayLinkedList(root);
    return 0;
    }


*/
