#include <iostream>
using namespace std;
int main(){
    int n,i,j = 0;
    cout<< "Enter number of elements in array: ";
    cin >> n;
    int arr[n];
    for(i = 0;i<n;i++){
        cout << "Enter element " << i << ": ";
        cin >> arr[i];
        }
    int arrbool[n+1];
    for(i = 0;i<n+1;i++){
        arrbool[i] = 0;
        }
    for(i = 0;i<n;i++){
        if(arr[i]<=n+1 && arr[i]>=1){
            arrbool[arr[i]-1] = 1;
            }
        }
    for(i = 0;i<n+1;i++){
        if(arrbool[i] == 0){
            cout << i+1 << " Is smallest missing positive number.";
            break;
            }
        }
    return 0;
    }
