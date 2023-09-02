#include <iostream>
#include <stack>

using namespace std;

class Stack {
private:
    stack<int> data;

public:
    void push(int value) {
        data.push(value);
    }

    int pop() {
        int value = data.top();
        data.pop();
        return value;
    }

    bool isEmpty() {
        return data.empty();
    }

    int top() {
        return data.top();
    }

    void sort();
};

void sortedInsert(Stack &stk, int value) {
    if (stk.isEmpty() || value > stk.top()) {
        stk.push(value);
    } else {
        int temp = stk.top();
        stk.pop();
        sortedInsert(stk, value);
        stk.push(temp);
    }
}

void Stack::sort() {
    if (!isEmpty()) {
        int value = top();
        pop();
        sort();
        sortedInsert(*this, value);
    }
}

int main() {
    Stack stk;
     stk.push(5);
    stk.push(-7);
    stk.push(8);
    stk.push(13);
    stk.push(2);


    cout << "Original Stack: ";
    while (!stk.isEmpty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;

    stk.push(5);
    stk.push(-7);
    stk.push(8);
    stk.push(13);
    stk.push(2);

    stk.sort();

    cout << "Sorted Stack: ";
    while (!stk.isEmpty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;

    return 0;
}