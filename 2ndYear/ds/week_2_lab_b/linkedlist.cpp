#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void display() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    static void display(Node* start) {
        if (!start) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = start;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != start);
        cout << endl;
    }

    void splitCircularList(Node** firstHalf, Node** secondHalf) {
        if (!head || !head->next) {
            *firstHalf = head;
            *secondHalf = nullptr;
            return;
        }

        Node* slow = head;
        Node* fast = head->next;

        while (fast != head && fast->next != head) {
            slow = slow->next;
            fast = fast->next->next;
        }

        *firstHalf = head;
        *secondHalf = slow->next;

        slow->next = head;
        Node* temp = *secondHalf;

        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = *secondHalf;
    }
};

int main() {
    CircularLinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    cout << "Original List: ";
    list.display();

    Node* firstHalf = nullptr;
    Node* secondHalf = nullptr;

    list.splitCircularList(&firstHalf, &secondHalf);

    cout << "First Half: ";
    CircularLinkedList::display(firstHalf);

    cout << "Second Half: ";
    CircularLinkedList::display(secondHalf);

    return 0;
}