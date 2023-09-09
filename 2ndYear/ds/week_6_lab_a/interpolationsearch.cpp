#include <iostream>
using namespace std;

int interpolationSearch(int *arr,int lo, int hi, int x){
    int mid = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));
    if(lo > hi){
        return -1;
    }
    if(x > arr[mid]){
        interpolationSearch(arr,mid+1,hi,x);
    }

    else if(x  == arr[mid]){
        return mid;
    }

    else{
        interpolationSearch(arr, lo, mid - 1, x);
    }
}

int main(){
    int len;
    cout << "Enter length of array : ";
    cin >> len;
    int *arr = new int[len];
    cout << "Enter array : ";

    for(int i = 0; i <len;i++){
        cin >> arr[i];
    }
    int x;
    cout << "Enter element you are looking for : ";
    cin >> x;
    int ans = interpolationSearch(arr,0,len-1,x);
    cout << ans << endl;
    return 0;
}