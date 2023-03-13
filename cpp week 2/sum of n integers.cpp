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
    int sum = 0;
    for(int i = 0; i<n ;i++){
        sum += arr[i];
    }
    cout << "Sum of all integers in  the array is : " << sum;
    return 0;
    }
