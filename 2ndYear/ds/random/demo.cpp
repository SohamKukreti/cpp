#include <iostream>
using namespace std;

struct Node{
    int info;
    Node * next;
};



void f1(Node *start){
    if(start == NULL) return ;
    else{
        cout << start->info;
        f1(start->next);
        cout << start->info;
        f1(start->next);
        cout << start->info;
    }
}
int main(){
    Node *start = new Node;
    Node *n1 = new Node;
    Node *n2 = new Node;
    start->info = 5;
    n1->info = 6;
    n2->info = 7;
    start->next = n1;
    n1->next = n2;

    f1(start);
}