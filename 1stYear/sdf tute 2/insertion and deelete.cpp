#include <iostream>
using namespace std;
class student{
    public : int totalsub;
    public : int *marks = new int[totalsub];

    void replace(int *marks,int pos,int n){
        for(int i = totalsub-1;i>=pos;i--){
            marks[i] = marks[i-1];
        }
        marks[pos] = n;
        }

    void display(){
        for(int i = 0;i<totalsub;i++){
            cout << marks[i] << " ";
        }
        cout << endl;
        }

    void insert(int *marks,int pos, int n,int len){
        for(int i = totalsub;i>=pos;i--){
            marks[i] = marks[i - 1];
        }
        marks[pos] = n;
        totalsub++;
        }

    void deletion(int *marks,int pos){
        for(int i = pos;i<totalsub;i++){
            marks[i] = marks[i+1];
        }
        totalsub--;
        }
    };

int main(){
    student s1;
    cout << "Enter number of subjects: ";
    cin >> s1.totalsub;
    cout << "Enter marks in all subjects: ";
    for(int i = 0;i<s1.totalsub;i++){
        cin >> s1.marks[i];
    }
    s1.insert(s1.marks,3,78,s1.totalsub);
    s1.display();
    s1.deletion(s1.marks,2);
    s1.display();
    delete s1.marks;
    return 0;
    }

