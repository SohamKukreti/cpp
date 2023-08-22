#include <iostream>
using namespace std;

class Stack{
public:
    int *s1;
    int top;
    int size;
    Stack(int x){
        s1 = new int[x];
        size = x;
        top = -1;
    }

    void push(int x){
        if(top == size-1){
            cout << "STAck is full";
        }
        else{
            s1[++top] = x;
        }
    }
    int pop(){
        if(top == -1) cout << "Stack is empty!";
        else {
            int x = s1[top];
            top--;
            return x;
        }
    }
    void display(){
        for(int i = 0 ;i <= top;i++){
            cout << s1[i] << " ";
        }
    }
    void peek(){
        cout << s1[top] << endl;
    }
};

int main(){
    Stack s1(10);
    for(int i = 0;i<10;i++){
        s1.push(i*10);
    }
    int size = s1.top + 1;
    Stack s2(size/2);
    Stack s3(size - (size/2));
    for(int i = 0;i<size/2;i++){
        s2.push(s1.pop());
    }
    for(int i = size/2;i<size;i++){
        s3.push(s1.pop());
    }
    cout << endl;
    s2.display();
    cout << endl;
    s3.display();
    Stack s4(size);

    for(int i = s3.top ;i >= 0; i--){
        s4.push(s3.pop());
    }
     for(int i = s2.top ;i >=0; i--){
        s4.push(s2.pop());
    }
    cout << endl;
    s4.display();
    cout << endl;
    return 0;
}