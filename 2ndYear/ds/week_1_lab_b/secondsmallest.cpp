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
    for(int i = 0;i<len;i++){
        for(int j = 0;j<len-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }


    cout << "Second smallest element is : " << arr[1] << endl;
    return 0;
}