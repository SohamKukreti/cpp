#include <iostream>
using namespace std;

class First{

    private:
        string studentName;

    public:

        First(string s){
            studentName = s;
            }
        void printname(){
            cout << studentName;
            }

    };



int main(){
    First s1("Soham Kukreti");
    s1.printname();
    return 0;
    }
