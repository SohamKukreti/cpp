#include <iostream>
using namespace std;

void insertionSort(int *arr, int len){
    for(int i = 1;i<len-1;i++){
        int j = i-1;
        int temp = arr[j+1];
        while(temp<arr[j] && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
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
    insertionSort(arr,len);
    cout << "Sorted Array : ";
    for(int i = 0;i<len;i++){
        cout <<  arr[i] << " ";
    }
    cout << endl;
    return 0;
    return 0;
}
