#include <iostream>
using namespace std;

int *mergeArrays1(int *arr1,int *arr2,int len1,int len2){
    int *arr3 = new int[len1+len2];
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < len1 || j < len2){
        if(i >= len1){
            while(j < len2){
                arr3[k++] = arr2[j++];
            }
        }
        else if(j >= len2){
            while(i < len1){
                arr3[k++] = arr1[i++];
            }
        }
        else{
             if(arr1[i]<=arr2[j]){
            arr3[k++] = arr1[i++];
            }
            else if(arr1[i]>arr2[j]){
                arr3[k++] = arr2[j++];
            }
        }
       
    }
    return arr3;
}

int *mergeArrays(int *arr1,int s1,int e1,int s2,int e2){
    int len1 = e1 - s1 + 1;
    int len2 = e2 - s2 + 1;
    int *arr3 = new int[len1+len2];
    int i = s1;
    int j = s2;
    int k = 0;
    while(i < e1 + 1 || j < e2 + 1){
        if(i >= e1 + 1){
            while(j < e2 + 1){
                arr3[k++] = arr1[j++];
            }
        }
        else if(j >= e2 + 1){
            while(i < e1 + 1){
                arr3[k++] = arr1[i++];
            }
        }
        else{
            if(arr1[i]<=arr1[j]){
                arr3[k++] = arr1[i++];
            }
            else if(arr1[i]>arr1[j]){
                arr3[k++] = arr1[j++];
            }
        }
       
    }
    return arr3;
}

void merge(int *arr,int s,int mid,int e){
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int *left = new int[len1];
    int *right = new int[len2];

    for(int i = 0;i<len1;i++){
        left[i] = arr[s + i];
    }

    for(int j = 0 ; j < len2;j++){
        right[j] = arr[mid+1+j];
    }

    int i = 0;
    int j = 0;
    int k = s;

    while(i < len1 && j < len2){

        if(left[i]<right[j]){
            arr[k++] = left[i++];
        }
        else if(left[i]>right[j]){
            arr[k++] = right[j++];
        }

    }

    while(i < len1){
        arr[k++] = left[i++];
    }
    while(j < len2){
        arr[k++] = right[j++];
    }
    delete[] left;
    delete[] right;

}
void mergeSort(int *arr,int start,int end){
    if (start < end) {
        int mid = start + (end - start) / 2; 
        mergeSort(arr, start, mid); 
        mergeSort(arr, mid + 1, end); 
        merge(arr, start, mid, end);
    }
    else{
        return ;
    }
}

int main(){
    int *arr;
    int len;
    cout << "enter length of array : ";
    cin >> len;
    arr = new int[len];
    cout << "enter array : " << endl;
    for(int i = 0;i<len;i++){
        cin >> arr[i];
    }
    mergeSort(arr,0,len-1);
    //int *arr3 = mergeArrays(arr,0,(len/2) - 1,(len/2),len - 1);
    for(int i = 0 ; i < len;i++){
        cout << arr[i] << " ";
    }
    return 0;
}