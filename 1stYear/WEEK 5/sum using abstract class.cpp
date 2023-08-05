#include <iostream>
using namespace std;
class A{
    protected:
        int a,b;
    public:
        A() {
            a = 1;
            b = 1;
            }
        A(int x, int y){
            a = x;
            b = y;
            }
        virtual void sum() = 0;
    };

class B : public A{
    public:
        B(int x, int y){
            a = x;
            b = y;
            }
        void sum(){
            cout << "Sum of the 2 numbers is: " << a + b;
            }
    };

int main(){
    A *a = new B(4,5);
    a->sum();
    return 0;
    }
