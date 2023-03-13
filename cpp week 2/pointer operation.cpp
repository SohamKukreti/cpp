#include <iostream>
using namespace std;
int main(){
    int arr[] = {10,100,200};
    int *p = arr;
    for(int i = 0; i < 3; i++){
        cout << "Address of arr [" << i << "]: "<< p << endl;
        cout << "Value of arr [" << i << "]: "<< *p << endl;
        p++;
    }
    p--;
    for(int i = 2; i >= 0; i--){
        cout << "Address of arr [" << i << "]: "<< p << endl;
        cout << "Value of arr [" << i << "]: "<< *p << endl;
        p--;
    }
    return 0;
    }
