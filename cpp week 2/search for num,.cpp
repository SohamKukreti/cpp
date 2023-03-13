#include <iostream>
using namespace std;
int main(){
    int arr[] = {3,67,5,8,5,79};
    int n;
    cout << "Enter number you wish to search: ";
    cin >> n;
    bool flag = false;
    for(int i = 0;i<6;i++){
        if(arr[i] == n){
            cout << n << " Found at index " << i << endl;
            flag = true;
        }
    }
    if(flag == false){
        cout << "Element not present in the array";
    }
    return 0;
    }
