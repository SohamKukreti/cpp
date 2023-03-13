#include <iostream>
using namespace std;

class Book{
    private:
        int bno;
        string bname;
        string author;
        string publisher;
        int price;
        int nocopyissued;
        int nocopy;
    public:
        Book(int bno,string bname,string author,string publisher,int price,int nocopy,int nocopyissued){
            this->bno = bno;
            this->bname = bname;
            this->author = author;
            this->publisher = publisher;
            this->price= price;
            this->nocopy = nocopy;
            this->nocopyissued = nocopyissued;
            }
        Book(){
            this->bno = 0;
            this->bname = "";
            this->author = "";
            this->publisher = "";
            this->price= 0;
            this->nocopy = 0;
            this->nocopyissued = 0;
            }
        void issueBook(){
            if(nocopy > 0){
                cout << "Book has been issued." << endl;
                nocopy -=1;
                nocopyissued +=1;
            }
            else{
                cout << "Cannot issue book" << endl;
            }
        }

        void returnBook(){
            if(nocopyissued > 0){
                cout << "Book has been returned.";
                nocopy +=1;
                nocopyissued -=1;
            }
            else{
                cout << "Cannot return book";
            }
        }

        void displayBookinfo(){
            cout << this->bno << endl;
            cout << this->bname << endl;
            cout << this->author << endl;
            cout << this->publisher << endl;
            cout << this->price << endl;
            cout << this->nocopy << endl;
            cout << this->nocopyissued << endl;
            }


    };

int main(){
    Book b1(1,"Sherlock Holmes","Arthur Conan Doyle","Penguin Books",399,3,0);
    b1.issueBook();
    b1.issueBook();
    b1.returnBook();
    b1.displayBookinfo();
    return 0;
    }
