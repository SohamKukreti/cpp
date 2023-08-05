#include <iostream>
using namespace std;

class integer{
    public:
        int a;
        integer(){
            a = 1;
            }
        integer(int a){
            this->a = a;
            }
        int operator++(){
            a++;
            return a;
            }
        int operator++(int){
            a++;
            return a;
            }
    };


int main(){
    integer a(10);
    cout << a++;

    }
