#include <iostream>
using namespace std;

struct Node{
int data;
Node *link;
};

class linkedlist{
private:
    Node *head;
public:
    linkedlist(){
        head = NULL;
    }
    void addNode(int x){
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
            cout << temp->data << " ";
            temp = temp->link;
        }
    }
    void deleteNode(Node *n1){
        Node *curr = head->link;
        Node *prev = head;
        if(head == n1){
            delete prev;
            head = curr;
        }
        else{
            while(curr != NULL){
                if(curr == n1){
                    prev->link = curr->link;
                    delete curr;
                    break;
                }
                prev = curr;
                curr = curr->link;
            }
        }
    }

    void del_dup()
{
    Node *temp=head;
    Node *ptr=NULL;
    Node *temp1=head;

    while(temp!=NULL)
    {
        ptr=temp->link;
        temp1 = temp;
        while(temp1->link!=ptr)
            {
                temp1=temp1->link;
            }
        while(ptr!=NULL)
        {

            if(temp->data==ptr->data)
            {
                temp1->link=ptr->link;
                Node *fwd=ptr;
                ptr=ptr->link;
                delete(fwd);

            }
            else
            {   
                temp1 = temp1->link;
                ptr=ptr->link;
            }
        }
        temp=temp->link;

    }

}


    void deleteDuplicates(){
        Node *temp1 = head;
        while(temp1!= NULL){
            Node *temp2 = temp1->link;
            while(temp2 != NULL){
                if(temp1->data == temp2->data){
                    Node *temp3 = temp2;
                    temp2 = temp2->link;
                    deleteNode(temp3);
                    }
                else{
                    temp2 = temp2->link;
                }
                
            }
        temp1= temp1->link;
        }
    }

};


int main(){
    linkedlist l1;
    for(int i = 1;i<=10;i++){
        int n;
        cout << "Enter value : ";
        cin >> n;
        l1.addNode(n);
    }
    l1.del_dup();
    //l1.deleteDuplicates();
    l1.display();
    return 0;
}