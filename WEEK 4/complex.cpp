#include <iostream>
using namespace std;
class Complex{
    private:
        int a;
        int b;
    public:
        Complex(){
            a = 1;
            b = 1;
        }
        Complex(int a, int b){
            this->a = a;
            this->b = b;
            }
        Complex operator+(Complex c2){
                Complex c3;
                c3.a = a + c2.a;
                c3.b = b + c2.b;
                return c3;
            }
        int getReal(){
            return a;
        }

        int getImaginary(){
            return b;
        }
    };
int main(){
    Complex c1(1,3);
    Complex c2(4,5);
    Complex c3 = c1 + c2;
    cout << c3.getReal() << " + " << c3.getImaginary() << "i";
    }
