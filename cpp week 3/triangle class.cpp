#include <iostream>
#include <math.h>
using namespace std;
class triangle{
    private:
        int a;
        int b;
        int c;


    public:
        triangle(){
            a = 3;
            b = 4;
            c = 5;
        }
        triangle(int x,int y,int z){
            a = x;
            b = y;
            c = z;
            }
        float area(){
            float s = (a+b+c)/2.0;
            float ar = sqrt(s*(s-b)*(s-a)*(s-c));
            return ar;
            }
        int perimeter(){
            return a+b+c;
            }
    };



int main(){
    triangle t1(2,5,6);
    cout << "Area is: " << t1.area() << endl;
    cout << "Perimeter: " << t1.perimeter();
    return 0;
    }
