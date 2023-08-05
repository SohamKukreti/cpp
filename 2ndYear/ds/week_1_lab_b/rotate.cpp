#include <iostream>
using namespace std;
int main(){
    int len;
    cout << "Enter the size of the array : ";
    cin >> len;
    int *arr = new int(len);
    for(int i = 0;i<len;i++){
        cout << "Enter element of array : ";
        cin >> arr[i];
    }
    int n;
    cout << "Enter how many times you wish to rotate the array : ";
    cin >> n;
    for(int i = 0;i<n;i++){
        int temp = arr[0];
        int j;
        for(j = 0;j<len-1;j++){
            arr[j] = arr[j+1];
        }
        arr[j] = temp;
    }
    for(int i = 0;i<len;i++){
        cout << arr[i] << " ";
    }
    return 0;
}