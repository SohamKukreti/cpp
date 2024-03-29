#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *link;
};

class Stack{
private:
    Node *top;

public:
    Stack(){
        top = NULL;
    }
    void push(int x){
        Node *n1 = new Node;
        n1->data = x;
        n1->link = top;
        top = n1;
    }

    void pop(){
        if(top == NULL){
            cout << "Stack is empty bruddah";
        }
        else{
            Node *temp = top;
            top = temp->link;
            delete temp;
        }
    }

    void display(){
        Node *temp = top;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->link;
        }
    }

};

bool checkPrime(int x){
    bool ifPrime = true;
    for(int i = 2;i<x;i++){
        if(x%i == 0){
            ifPrime = false;
        }
    }
    return ifPrime;
}



int main(){
    Stack s1;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    for(int i = 2;i<=n;i++){
        if(n%i == 0){
            bool pf = checkPrime(i);
            if(pf){
                s1.push(i);
            }
        }

    }
    s1.display();
    cout << endl;
    return 0;
}