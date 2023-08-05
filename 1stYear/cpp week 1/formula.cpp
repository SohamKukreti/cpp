#include <iostream>
using namespace std;
int main(){
    int a,b,c,d;
    cout << "Enter value of a,b,c,d: ";
    cin >> a >> b >> c >> d;
    if(b-c == 0){
        cout << "Cannot divide by zero Error. Retry with different input";
        }
    else{
        float x = ((float)a / (b - c)) + d;
        cout<<"Value of x is: " << x;
    }

    return 0;
    }
