#include <iostream>
using namespace std;

class Queue {
public:
    int *arr;
    int f;
    int r;
    int max_size;

    Queue(int x) {
        arr = new int[x];
        max_size = x;
        f = -1;
        r = -1;
    }

    bool isFull() {
        if ((r == max_size - 1 && f == 0) || (r + 1) % max_size == f) return true;
        else return false;
    }

    void enqueue(int x) {
        if (isFull()) cout << "Queue is full!";
        if (f == -1) {
            f = 0;  // Update front when enqueueing the first element
            r = 0;
            arr[r] = x;
        } else {
            r = (r + 1) % max_size;
            arr[r] = x;
        }
    }

    bool isEmpty() {
        if (f == -1) return true;
        else return false;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!";
            return -1;  // Return a default value when the queue is empty
        }
        if (f == r) {
            int x = arr[f];
            f = -1;
            r = -1;
            return x;
        } else {
            int x = arr[f];
            f = (f + 1) % max_size;
            return x;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!";
            return;
        }

        int i = f;
        do {
            cout << arr[i] << " ";
            i = (i + 1) % max_size;
        } while (i != (r + 1) % max_size);

        cout << endl;
    }
};

int main() {
    Queue q1(5);
    for (int i = 0; i < 5; i++) {
        q1.enqueue(i * 10);
    }
    q1.dequeue();
    q1.dequeue();
    q1.enqueue(1);
    q1.enqueue(2);

    cout << endl;
    q1.display();

    return 0;
}
