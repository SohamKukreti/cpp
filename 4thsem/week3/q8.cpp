#include <iostream>
using namespace std;

int countOcc(int *arr,int l,int r, int num){
    int len = r - l + 1;
    int cnt = 0;
    for(int i = 0;i < len;i++){
        if(arr[i] == num) cnt++;
    }
    return cnt;

}


int findMajority(int *arr,int l, int r){
    if(l == r) return arr[l];
    int n = (r - l)  +1;
    int mid = (l+r)/2;
    int leftMaj = findMajority(arr,l,mid);
    int rightMaj = findMajority(arr,mid+1,r);
    if(leftMaj == rightMaj) return leftMaj;
    int leftCnt = countOcc(arr,l,r,leftMaj);
    int rightCnt = countOcc(arr,l,r,rightMaj);
    if(leftCnt > n/2) return leftMaj;
    if(rightCnt > n/2) return rightMaj;
    return -1;
}

int main(){
    int *arr;
    int len;
    cout << "Enter length of array : ";
    cin >> len;
    arr = new int[len];
    for(int i = 0;i< len ; i++) cin >> arr[i];
    cout << findMajority(arr,0,len-1);
    return 0;
}
