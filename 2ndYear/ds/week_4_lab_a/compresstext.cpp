#include <iostream>
using namespace std;

struct Node{
char data;
Node *link;
};

class Q{
public:
    Node *head;
    Node *rear;
    Q(){
        head = NULL;
        rear = NULL;
        }
    void enqueue(char x){
        Node *n1 = new Node;
        n1->data = x;
        if(head == NULL){
            head = n1;
            rear = n1;
            n1->link = NULL;
        }
        else{
            rear->link = n1;
            rear = n1;
            n1->link = NULL;
        }
        }
    char dequeue(){
        Node *temp = head;
        head = head->link;
        char x = temp->data;
        delete temp;
        return x;
        }
    void display(){
        Node *temp = head;
        while(temp != NULL){
            cout << temp->data;
            temp = temp->link;
        }
    }
    bool isEmpty(){
        if(head == NULL){
            return true;
        }
        else return false;
    }
};

int main(){
    Q q1;
    cout <<"Enter string : ";
    string str1;
    getline(cin,str1);
    for(int i = 0;i<str1.length();i++){
        if(str1[i] == ' ') continue;
        else{
            q1.enqueue(str1[i]);
        }
    }

    Q q2;
    int count = 1;
    while(!q1.isEmpty()){
        char c = q1.dequeue();
        if(q2.rear != NULL && c == q2.rear->data){
            count++;
        }




        else if(q2.rear != NULL && c != q2.rear->data){
            if(count > 1) q2.enqueue(count+48);
            q2.enqueue(c);
            count = 1;

        }
        if(q2.rear == NULL){
            q2.enqueue(c);
        }









    }
    q2.display();
    cout << endl;
    return 0;
    }
