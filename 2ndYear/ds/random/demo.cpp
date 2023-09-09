#include <iostream>
using namespace std;
void SelectionSort(int *arr, int len){
    int cnt = 0;
    for(int i = 0;i<len-1;i++){
        int j = 0;
        int min = i;
        for(j = i+1;j<len;j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        if(i != min){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
            cnt++;
        }
        
    }
    cout << cnt << endl;
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
    SelectionSort(arr,len);

    // cout << "Sorted Array : ";
    // for(int i = 0;i<len;i++){
    //     cout <<  arr[i] << " ";
    // }
    return 0;
}