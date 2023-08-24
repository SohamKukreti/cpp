#include <iostream>
using namespace std;
struct Node{
char data;
Node *link;
};

class stack{
public:
    Node *top;
    stack(){
        top = NULL;
    }

    void push(char x){
        Node *n1 = new Node;
        n1->data = x;
        n1->link = top;
        top = n1;
    }
    char pop(){
        Node *temp = top;
        top = temp->link;
        char c = temp->data;
        delete temp;
        return c;
    }
    void display(){
        Node *temp = top;
        while(temp!= NULL){
            cout << temp->data << " ";
            temp = temp->link;
        }
    }
};


int main(){
    stack s1;
    string str1;
    cout << "Enter a string : ";
    cin >> str1;
    int len = str1.length();
    for(int i = 0 ; i < len;i++){
        if(str1[i] == '(' || str1[i] == '{' || str1[i] == '['){
            s1.push(str1[i]);
        }
    }
    s1.display();


    return 0;
}