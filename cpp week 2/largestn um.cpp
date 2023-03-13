#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the integers in the array: ";
    for(int i = 0; i<n ; i++){
        cin >> arr[i];
    }
    int maxnum = arr[0];
    for(int i = 0; i<n ;i++){
        if(arr[i]>maxnum){
            maxnum = arr[i];
        }
    }
    cout << "Maximum integer in  array is : " << maxnum;
    return 0;
    }
