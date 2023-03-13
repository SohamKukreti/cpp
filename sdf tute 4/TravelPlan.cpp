#include <iostream>
using namespace std;
class student{
    public:
        int len;
        int *marks;

        student(){
            len = 5;
            marks = new int[5];
            }
        student(int x,int *p){
            len = x;
            marks = p;
            }
        void deleteElement(int n){
            for(int i = n;i<len;i++){
                marks[i] = marks[i+1];
            }
            len--;
            }
        void insertElement(int pos,int data){
            for(int i = len;i>pos;i--){
                marks[i] = marks[i-1];
            }
            marks[pos] = data;
            len++;
            }
        void display(){
            for(int i = 0;i<len;i++){
                cout << marks[i] << " ";
            }
            }
        ~student(){
            delete marks;
            }
    };
int main(){
    int *marks = new int[5];
    marks[0] = 95;
    marks[1] = 90;
    marks[2] = 85;
    marks[3] = 92;
    marks[4] = 97;
    student s1(5,marks);
    //s1.deleteElement(2);
    s1.insertElement(2,70);
    s1.display();
    }
