#include <iostream>
using namespace std;
void selectionSort(int *arr, int len){
    for(int i = 0;i<len-1;i++){
        int small = i;
        for(int j = i;j<len;j++){
            if(arr[j] < arr[small]){
                small = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[small];
        arr[small] = temp;
    }
}

int main(){
    int *arr;
    int len;
    cout << "enter length of array : ";
    cin >> len;
    arr = new int[len];
    cout << "enter array : " << endl;
    for(int i = 0;i<len;i++){
        cin >> arr[i];
    }
    selectionSort(arr,len);
    cout << "Sorted Array : ";
    for(int i = 0;i<len;i++){
        cout <<  arr[i] << " ";
    }
    cout << endl;
    return 0;    
}