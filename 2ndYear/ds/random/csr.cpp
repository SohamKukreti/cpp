#include <iostream>
using namespace std;

struct Node{
int data;
int pos;
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

    void addNode(int x,int pos){
        Node *n1 = new Node;
        n1->data = x;
        n1->pos = pos;
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
            cout << temp->data << " : " << temp->pos << " ";
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

using namespace std;
int main(){
    int row;
    int col;
    cout << "Enter row and col : ";
    cin >> row;
    cin >> col;
    int arr[row][col];
    linkedlist *arr1;
    arr1 = new linkedlist[row];
    cout << "Enter array : ";
    for(int i = 0 ; i <row;i++){
        for(int j = 0 ; j< col;j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0 ; i <row;i++){
        for(int j = 0 ; j< col;j++){
            if(arr[i][j] != 0){
                arr1[i].addNode(arr[i][j],j);
            }
        }
    }


    for(int i = 0;i < row; i++){
        arr1[i].display();
        cout  << endl;
    }
    return 0;
    }
