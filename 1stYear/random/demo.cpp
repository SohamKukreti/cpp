#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter how many elements you want in the array: ";
    cin >> n;
    int * arr1 = new int[n];
    int *arr =new int[n];
    for(int i = 0;i<n;i++){
        arr[i] = rand()%10;
    }
    for(int i = 0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    int j = 0;
    for(int i = 0;i<n;i++){
        if(arr[i]%2 == 0){
            cout << arr[i];
        }
        else{
           arr1[j++] = arr[i];
        }
    }
    cout << endl;
    for(int i = 0;i<j;i++){
        cout << arr1[i] << " ";
    }
    cout << endl;
    return 0;

    }
