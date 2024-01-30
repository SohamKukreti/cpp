#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(int *arr,pair<int,int> *pointarr, int l,int m, int r){
    int len = r -l +1;
    int *temp = new int[len];
    pair<int,int> *tempPointArr = new pair<int,int>[len];
    int i = l;
    int j = m + 1;
    int k = 0;
    while(i <=m && j <= r){
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            tempPointArr[k] = pointarr[i];
            k++;
            i++;
        }
        else{
            temp[k] = arr[j];
            tempPointArr[k] = pointarr[j];
            k++;
            j++;
        }
    }
    while(i <= m){
            tempPointArr[k] = pointarr[i];
            temp[k++] = arr[i++];
    }
    while(j<=r){
        tempPointArr[k] = pointarr[j];
        temp[k++] = arr[j++];
    }

    for(int i = 0;i < len;i++){
        pointarr[i] = tempPointArr[i];
        arr[i] = temp[i];
    }
}

void mergesort(int *distarr,pair<int,int> *arr, int l,int r){
    if(l >= r) return;
    int mid = (l + r)/2;
    mergesort(distarr,arr,l,mid);
    mergesort(distarr,arr,mid+1,r);
    merge(distarr,arr,l,mid,r);
}


int main(){
    pair<int,int> *arr;
    int len;
    cout << "Enter number of points : ";
    cin >> len;
    arr = new pair<int,int>[len];
    int x;
    int y;
    for(int i = 0 ;i < len;i++){
        cin >> x;
        cin >> y;
        arr[i].first = x;
        arr[i].second = y;
    }
    map <pair<int,int>,int> m1;
    int *distarr = new int[len];
    for(int i = 0;i < len;i++){
        float distsqr;
        int x = arr[i].first;
        int y = arr[i].second;
        distsqr = (x - 0)*(x-0) + (y - 0)*(y - 0);
        m1[{x,y}] = distsqr;
        distarr[i] = distsqr;
    }
    mergesort(distarr, arr, 0,len-1);

    int k;
    cout << "Enter value of k : ";
    cin >> k;

    for(int i = 0;i<k;i++){
        cout << arr[i].first << ", " << arr[i].second << endl;
    }

    return 0;
    }
