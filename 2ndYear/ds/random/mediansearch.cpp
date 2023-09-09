#include <iostream>
#include <cstdlib>
using namespace std;

int findKthSmallest(int *arr, int lo, int hi, int k){
    int len = hi - lo + 1;
    int index = rand()%len;
    int s1[10];
    int s2[1];
    int s3[10];
    int arr1len = 0;
    int arr2len = 0;
    int arr3len = 0;
    for(int i = 0 ;i<len;i++){
        if(arr[index]>arr[i]){
            s1[arr1len] = arr[i];
            arr1len++;
        }
        else if(arr[index] == arr[i]){
            s2[arr2len] = arr[i];
            arr2len++;
        }
        else{
            s3[arr3len] = arr[i];
            arr3len++;
        }
    }
    if(arr1len >= k){
        findKthSmallest(s1,0,arr1len-1,k);
    }
    else if(arr1len + arr2len >= k){
        return arr[index];
    }
    else{
        findKthSmallest(s3,0,arr3len-1,k - arr1len - arr2len);
    }

}

int main(){
    int *arr;
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    arr = new int[n];
    cout << "Enter array please sir  : "; 
    for(int i = 0 ;i < n;i++){
        cin >> arr[i];
    } 
    int k;
    cout << "Enter value of k : ";
    cin >> k;
    cout << findKthSmallest(arr,0,n-1,k) << endl;

    return 0;
}