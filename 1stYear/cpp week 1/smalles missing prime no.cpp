#include <iostream>
using namespace std;
int main(){
    int n,i,j;
    cout << "Enter number of elements in array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for(i = 0;i<n;i++){
        cin >> arr[i];
    }
    int max = arr[0];
    for(i = 0;i<n;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    bool primeno[max+1];
    primeno[0] = false;
    primeno[1] = false;
    for(i = 2;i < max+1;i++){
        int flag = 0;
        for(j = 2;j < i;j++){
            if(i%j == 0){
                flag = 1;
            }
        }
        if(flag == 0){
            primeno[i] = true;
        }
        else{
            primeno[i] = false;
        }
    }


    for(i = 2;i < max+1;i++){
        int flag = 0;
        for(j = 0;j<n;j++){
            if(primeno[i] == true && i == arr[j]){
                flag = 1;
            }
        }
        if(primeno[i] == true && flag == 0){
            cout << i << " is the smallest prime, which is not present in array..";
            break;
        }
    }
    if(i == max+1){
        cout << "All prime number present.";
    }
    return 0;
    }
