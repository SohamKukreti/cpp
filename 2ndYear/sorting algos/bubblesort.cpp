#include <iostream>
using namespace std;
void bubbleSort(int *arr, int len){
    for(int i = 0;i<len-1;i++){
        for(int j = 0;j<len-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int *arr;
    int len;
    cout << "enter lenght of array : ";
    cin >> len;
    arr = new int[len];
    cout << "enter array : " << endl;
    for(int i = 0;i<len;i++){
        cin >> arr[i];
    }
    bubbleSort(arr,len);
    cout << "Sorted Array : ";
    for(int i = 0;i<len;i++){
        cout <<  arr[i] << " ";
    }
    return 0;
}