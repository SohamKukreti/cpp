#include <iostream>
using namespace std;
struct node{
    int data;
    node *next;
    };

class LL{
    private:
        node *head = NULL;
    public:
        void insertNode(int n){
            node *tmp = new node;
            tmp -> data = n;
            tmp -> next = head;
            head = tmp;
            }
        void display(){
            node *tmp = new node;
            tmp = head;
            while(tmp != NULL){
                cout << tmp -> data << " ";
                tmp = tmp->next;
            }
            }
        void deleteitem(int n){
            node *tmp1 = new node;
            node *tmp2 = new node;
            tmp1 = head;
            if(tmp1->data == n){
                head = tmp1->next;
            }
            tmp1 = tmp1->next;
            tmp2 = head;
            while(tmp1 != NULL){
                if(tmp1->data == n){
                    tmp2->next = tmp1->next;
                }
                tmp1 = tmp1->next;
                tmp2 = tmp2->next;
            }
            }
    };

int main(){
    LL l;
    int n,num,del;
    char ch;
    cout << "Enter number of elements you want in the linked list: ";
    cin >> n;
    for(int i = 0;i<n;i++){
        cout << "Enter element to insert at beginning: ";
        cin >> num;
        l.insertNode(num);
    }
    //deleting an item
    while(true){
        cout << "Enter element you wish to delete: ";
        cin >> del;
        l.deleteitem(del);
        cout << "Do you wish to delete more elements?(Y/N): ";
        cin >> ch;
        if(ch == 'n' || ch == 'N'){
            break;
        }
    }

    cout << "Linked list after deleting an item: ";
    l.display();
    return 0;
    }
