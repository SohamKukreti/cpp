#include <iostream>
using namespace std;

int BinarySearch(string *arr,int lo, int hi, string x){
    int mid = (hi + lo) / 2;
    if(lo > hi){
        return -1;
    }
    if(x > arr[mid]){
        BinarySearch(arr,mid+1,hi,x);
    }

    else if(x  == arr[mid]){
        cout << "found!" << endl;
        return mid;
            }

    else{
        BinarySearch(arr, lo, mid - 1, x);
    }
}

int main(){
    int len;
    cout << "Enter length of array : ";
    cin >> len;
    string *arr = new string[len];
    cout << "Enter array : ";

    for(int i = 0; i <len;i++){
        cin >> arr[i];
    }

    cout << endl;
    string x;
    cout << "Enter string you are looking for : ";
    cin >> x;
    int ans = BinarySearch(arr,0,len-1,x);
    cout << ans << endl;
    return 0;
}