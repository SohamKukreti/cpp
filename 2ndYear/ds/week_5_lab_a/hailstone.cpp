#include <iostream>
using namespace std;
void hailstone(int n){
    if(n == 1){
        cout << n << endl;
        return ;
    }
    if(n%2 == 0){
        cout << n << " ";
        hailstone(n/2);
    }
    else{
        cout << n << " ";
        hailstone((n*3) + 1);
    }
}
int main(){
    hailstone(7);
    return 0;
}