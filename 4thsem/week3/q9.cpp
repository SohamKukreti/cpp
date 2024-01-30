#include <iostream>
#include <math.h>
using namespace std;

int findKthSmallest(int *arr,int l, int r, int k)
{
    int len = r - l + 1;
    int pivot = rand()%len;
    int *s1 = new int[len];
    int *s2 = new int[len];
    int *s3 = new int[len];
    int s1len = 0;
    int s2len = 0;
    int s3len = 0;

    for(int i = 0;i < len;i++){
        if(arr[i] < arr[pivot]){
            s1[s1len++] = arr[i];
        }
        else if(arr[i] == arr[pivot]){
            s2[s2len++] = arr[i];
        }
        else{
            s3[s3len++] = arr[i];
        }
    }

    if(k <= s1len) findKthSmallest(s1,l,s1len-1,k);
    else if(k <= s1len + s2len) return arr[pivot];
    else findKthSmallest(s3,l,s3len-1,k-s2len-s1len);

}

int main(){
    int *arr;
    int len;
    cout << "Enter length of array : ";
    cin >> len;
    arr = new int[len];
    for(int i = 0;i< len ; i++) cin >> arr[i];
    int k;
    cout << "Enter value of K : ";
    cin >> k;
    cout << findKthSmallest(arr,0,len-1,k);
    return 0;
}
