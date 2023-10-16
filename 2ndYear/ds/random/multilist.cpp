#include <iostream>

using namespace std;

#define SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

class Node
{
public:
    int data;
    Node* next;
    Node* child;
};

void flattenRow(Node *head){
    Node *tail = head;
    Node *cur = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    while(cur != tail){
        if(cur->child){
            tail->next = cur->child;
            Node *temp = cur->child;
            while(temp->next){
                temp = temp->next;
            }
            tail = temp;
        }
        cur = cur->next;

    }
    }
/*
void flattenCol(Node *head){
    Node *tail = head;
    Node *cur = head;
    while(tail->child != NULL){
        tail = tail->child;
    }
    while(cur != tail){
        if(cur->next){
            tail->child = cur->next;
            Node *temp = cur->next;
            while(temp->child){
                temp = temp->child;
            }
            tail = temp;
        }
        cur = cur->child;

    }

}

*/

Node* createList(int* arr, int n)
{
    Node* head = NULL;
    Node* p;
    int i;

    for (i = 0; i < n; ++i)
    {
        if (head == NULL)
            head = p = new Node();
        else
        {
            p->next = new Node();
            p = p->next;
        }

        p->data = arr[i];
        p->next = p->child = NULL;
    }

    return head;
}


Node * flattenCol(Node *head){
    if(head == NULL) return NULL;
    static Node *last = head;
    Node *next = head->next;
    if(head->child){
        head->next = flattenCol(head->child);
    }
    if(next){
        last->next = flattenCol(next);
    }
    return head;
    }

void display(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    }

Node* createList(void)
{
    int arr1[] = {10, 5, 12, 7, 11};
    int arr2[] = {4, 20, 13};
    int arr3[] = {17, 6};
    int arr4[] = {9, 8};
    int arr5[] = {19, 15};
    int arr6[] = {2};
    int arr7[] = {16};
    int arr8[] = {3};

    Node* head1 = createList(arr1, SIZE(arr1));
    Node* head2 = createList(arr2, SIZE(arr2));
    Node* head3 = createList(arr3, SIZE(arr3));
    Node* head4 = createList(arr4, SIZE(arr4));
    Node* head5 = createList(arr5, SIZE(arr5));
    Node* head6 = createList(arr6, SIZE(arr6));
    Node* head7 = createList(arr7, SIZE(arr7));
    Node* head8 = createList(arr8, SIZE(arr8));

    head1->child = head2;
    head1->next->next->next->child = head3;
    head3->child = head4;
    head4->child = head5;
    head2->next->child = head6;
    head2->next->next->child = head7;
    head7->child = head8;

    return head1;
}


int main(void)
{
    Node* head = NULL;
    head = createList();
    flattenCol(head);
    display(head);
    return 0;
}
