#include <iostream>
using namespace std;
class A{
    public:
        virtual void display1() = 0;
        virtual void display2(){
            cout << "This is display2() method of Base class" << endl;
            }
    };

class B : public A{
    public:
        void display1(){
            cout << "This is display1() method of Derived class" << endl;
            }
        void display2(){
            cout << "This is display2() method of Derived class" << endl;
            }
    };

int main(){
    A *a = new B;
    a->display1();
    a->display2();
        }
