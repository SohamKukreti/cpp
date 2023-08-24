
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




int main(){
	Stack s1;
	int numsys;
	cout << "Which number system do you want to convert to(b/w 2 and 9): ";
	cin >> numsys;
	int n;
	cout << "Enter a number in decimal notation: ";
	cin >> n;
	while(n > 0){
    	int rem = n%numsys;
    	n = n/numsys;
    	s1.push(rem);
	}
	s1.display();
	cout << endl;
	return 0;
}
