#include <iostream>
using namespace std;

int Partition(int *arr,int lo, int hi){
    int pivot = arr[hi];
    int j = lo;
    int i = j - 1;
    while(j<hi){
        if(arr[j]<pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        j++;
    }
    i++;
    int temp = arr[i];
    arr[i] = arr[hi];
    arr[hi] = temp;
    return i;
    }

void quickSort(int *arr,int lo,int hi){
    if(lo < hi){
         int p = Partition(arr,lo,hi);
        quickSort(arr,lo,p-1);
        quickSort(arr,p+1,hi);
    }

    }

int main(){
    int *arr;
    int len;
    cout << "Enter length of array : ";
    cin >> len;
    arr = new int[len];
    cout << "Enter array : ";
    for(int i = 0;i<len;i++){
        cin >> arr[i];
    }
    cout << "Sorted array : ";
    quickSort(arr,0,len-1);
    for(int i = 0;i<len;i++){
        cout << arr[i] << " ";
    }
    return 0;
    }
