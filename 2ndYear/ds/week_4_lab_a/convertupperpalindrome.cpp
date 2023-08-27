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

class Stack{
private:
    Node *top;

public:
    Stack(){
        top = NULL;
    }
    void push(char x){
        Node *n1 = new Node;
        n1->data = x;
        n1->link = top;
        top = n1;
    }

    char pop(){
        if(top == NULL){
            cout << "Stack is empty bruddah";
        }
        else{
            Node *temp = top;
            top = temp->link;
            char c = temp->data;
            delete temp;
            return c;
        }
    }

    void display(){
        Node *temp = top;
        while(temp != NULL){
            cout << temp->data;
            temp = temp->link;
        }
    }

};

int main(){
    string lower = "abcdefghijklmnopqrstuvwxyz";
    string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string str1;
    Stack s1;
    Q q1;
    cout << "ENter a string: ";
    cin >> str1;
    for(int i = 0;i<str1.length();i++){
        for(int j = 0;j<lower.length();j++){
            if(str1[i] == lower[j]){
                s1.push(upper[j]);
                q1.enqueue(upper[j]);
            }
            if(str1[i] == upper[j]){
                s1.push(lower[j]);
                q1.enqueue(lower[j]);
            }
        }
    }
    while(!q1.isEmpty()){
        char c1 = q1.dequeue();
        char c2 = s1.pop();
        if(c1 != c2){
            cout << "Not a palindrome";
            return 0;
        }
    }
    cout << "It is a palindrome!";
    return 0;
    }
