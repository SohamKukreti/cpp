#include <iostream>
#include <cstdlib>
using namespace std;

class Stack{
public:
    int top;
    int *arr;
    int size;
    Stack(int x){
        size = x;
        arr = new int[size];
        top = -1;
    }

    void push(int x){
        if(top == size - 1){
            cout << "Full stack" << endl;
        }
        else{
            top++;
            arr[top] = x;
        }
    }

    int pop(){
        if(top == -1){
            cout << "Stack is empty !" << endl;
        }
        else{
            
            int temp = arr[top];
            top--;
            return temp;
        }
    }

    int display(){
        for(int i = 0 ; i<=top;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int peek(){
        return arr[top];
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        return false;
    }

};

void sortedInsert(Stack *s,int x){
    if(s->isEmpty() || x > s->peek()){
        s->push(x);
        return;
    }

   
    int a = s->pop();
    sortedInsert(s,x);
    s->push(a);


}

void sortStack(Stack *s){
    if(s->isEmpty()){
        return;
    }
    int x = s->pop();
    sortStack(s);
    sortedInsert(s,x);
 

}



int main(){
    Stack *s1 = new Stack(5);
    int n;
    cout << "Enter n : ";
    for(int i = 0 ; i < 5 ; i++){
        cin >> n;
        s1->push(n);
    }
    s1->display();
    sortStack(s1);
    s1->display();
    return 0;
}