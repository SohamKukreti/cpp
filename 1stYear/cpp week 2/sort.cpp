#include <iostream>
using namespace std;
int main(){
    int arr[] = {3,67,5,8,78,2};
    int *p = arr;
    for(int i = 0;i<6;i++){
        for(int j = 0;j<5;j++){
                if(p[j]>p[j+1]){
                    int temp = p[j];
                    p[j]  = arr[j+1];
                    p[j+1] = temp;
                }
            }
    }
    for(int i = 0;i<6;i++){
        cout << p[i] << " ";
    }
    cout << endl <<"Reversed list: " << endl;
    for(int i = 5;i>=0;i--){
        cout << p[i] << " ";
    }

    return 0;
    }
