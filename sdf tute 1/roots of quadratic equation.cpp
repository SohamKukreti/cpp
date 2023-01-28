#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int a,b,c;
    cout << "Quadratic equation of form: ax^2 + bx + c." << endl;
    cout << "Enter value of a,b,c: ";
    cin >> a >> b >> c;
    int root1 = (-b + sqrt(b*b - 4*a*c))/2*a;
    int root2 = (-b - sqrt(b*b - 4*a*c))/2*a;
    cout << "The roots of the given equation are: " << root1 << ", " << root2;
    return 0;
    }
