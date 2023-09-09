#include <iostream>
using namespace std;
//lcm = (num1*num2)/hcf

int hcf(int a , int b){
    if(b > a){
        int c = a;
        a = b;
        b = c;
    }

    if(a%b == 0){
        return b;
    }
    hcf(b,a%b);
}

int lcm(int a,int b){
    return a*b/hcf(a,b);
}

int main(){
    int a, b;
    cout << "Enter first Number : ";
    cin >> a;
    cout << "Enter Second Number : ";
    cin >> b;
    cout << "LCM is : ";
    cout << lcm(a, b) << endl;
    
}



