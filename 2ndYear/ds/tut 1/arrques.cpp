#include <iostream>
using namespace std;

int *twicearr(int *arr,int len){
    int *arr2 = new int[len*2];
    int i;
    for(i = 0;i<len;i++){
        arr2[i] = arr[i];
    }
    for(int j = 0;j<len;j++){
        arr2[i+j] = arr[j]*2; 
    }
    return arr2;
}

int main(){
    int len;
    cout << "Enter length of array : ";
    cin >> len;
    int *arr = new int[len];
    for(int i = 0;i<len;i++){
        cout << "Enter element of array : ";
        cin >> arr[i];
    }
    int * arr2 = twicearr(arr,len);
    for(int i = 0;i<len*2;i++){
        cout << arr2[i];
    }
    cout << endl;
    return 0;
}