#include <iostream>
using namespace std;

struct KeyVal{
int key;
int val;
};

struct Node{
KeyVal data;
Node *link;
};

class linkedlist{
private:
    Node *head;
public:
    linkedlist(){
        head = NULL;
    }


    void addNode(KeyVal x){
        Node *n1 = new Node;
        n1->data = x;
        n1->link = NULL;
        if(head == NULL){
            head = n1;
        }
        else{
            Node *temp = head;
            while(temp->link != NULL){
                temp = temp->link;
            }
            temp->link = n1;
        }
    }

    void display(){
        Node *temp = head;
        while(temp!=NULL){
            cout << "Key : " << temp->data.key << " ";
            cout << "Value : " <<  temp->data.val << " ";
            temp = temp->link;
        }
    }
    void deleteNode(int x){
        Node *curr = head->link;
        Node *prev = head;
        if(head->data.key == x){
            delete prev;
            head = curr;
        }
        else{
            while(curr != NULL){
                if(curr->data.key == x){
                    prev->link = curr->link;
                    delete curr;
                    break;
                }
                prev = curr;
                curr = curr->link;
            }
        }
    }

    int searchKey(int key){
        Node *temp = head;
        while(temp != NULL){
            if(temp->data.key == key){
                return temp->data.val;
            }
            temp = temp->link;
        }
        return -1;
        }

};


class hashTable{
public:
    linkedlist *ht;
    int len;
    int b;
    hashTable(int n){
        ht = new linkedlist[n];
        len = n;
        b = 0;
    }

    int hashFunction(int key){
            return key%this->len;
        }

    void insertPair(KeyVal k1){
            int ind = hashFunction(k1.key);
            ht[ind].addNode(k1);
            cout << "Inserted!" << endl;
            b++;
        }

    void lookupPair(int key){
        int ind = hashFunction(key);
        int val = ht[ind].searchKey(key);
        if(val >= 0){
            cout << "found, value is : " << val << endl;
        }
        else{
            cout << "Key not found mate. " << endl;
        }
        }

    void deletePair(int key){
        int ind = hashFunction(key);
        ht[ind].deleteNode(key);
        b--;
        cout << "Deleted ! ";
        }

    void loadFactor(){
        float lf = (float)b/len;
        cout << lf << endl;
        }

    void currentState(){
        for(int i = 0;i<len;i++){
            ht[i].display();
        }
    }

    };


int main(){
    hashTable h1(13);
    KeyVal k1;
    k1.key = 153;
    k1.val = 10;
    KeyVal k2;
    k2.key = 174;
    k2.val = 20;
    KeyVal k3;
    k3.key = 169;
    k3.val = 30;

    h1.insertPair(k1);
    h1.insertPair(k2);
    h1.insertPair(k3);



    h1.lookupPair(k3.key);

    h1.deletePair(k3.key);

    h1.lookupPair(k3.key);

    h1.loadFactor();

    h1.currentState();

    return 0;
    }
