#include <iostream>
using namespace std;

class complex{

    private:
        int a;
        int b;

    public:

        complex(){
            a = 1;
            b = 1;
            }

        complex(int x,int y){
            a = x;
            b = y;
            }

        void setReal(int x){
            a = x;
            }

        void setImaginary(int y){
            b = y;
            }

        int getReal(){
            return a;
            }

        int getImaginary(){
            return b;
            }
        void sum(complex c1, complex c2){
                cout << "Sum of the 2 complex numbers: " << c1.a + c2.a << " + " << c1.b + c2.b << "i" << endl;
            }

        void diff(complex c1, complex c2){
                cout << "Difference of the 2 complex numbers: " << c1.a - c2.a << " + " << c1.b - c2.b << "i" << endl;
            }

        void product(complex c1, complex c2){
                cout << "Product of the 2 complex numbers: " << c1.a * c2.a << " + " << c1.b * c2.b << "i" <<endl;
            }
    };



int main(){
    complex c1;
    c1.setReal(4);
    c1.setImaginary(5);
    complex c2;
    c2.setReal(2);
    c2.setImaginary(3);
    c1.sum(c1,c2);
    c1.diff(c1,c2);
    c1.product(c1,c2);
    return 0;
    }
