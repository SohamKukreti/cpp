#include <iostream>
using namespace std;

void insertionSort(int *arr,int len)
{
	for(int i = 1;i<len;i++){
		int temp = arr[i];	
		int j = i;
		for(j = i;j>=0 && temp <= arr[j];j--){
			arr[j] = arr[j-1];	
			}
		j++;
		arr[j] = temp;		
		}
	}

int findPivot(int *arr, int l, int r)
{
	int p = r;
	int i = l-1;
	int j = l;
	for(;j<r;j++){
		if(arr[p]>=arr[j]){
			i++;
			swap(arr[i],arr[j]);
		}		
		}
	i++;
	swap(arr[i],arr[p]);
	return i;
}

void quickSort(int *arr, int l, int r){
	if(l >= r)
		return ;
	int pivot = findPivot(arr, l, r);
	quickSort(arr,l, pivot - 1);
	quickSort(arr,pivot+1,r);

}

int main(){
	int *arr;
	int len;
	cout << "Enter length of array : ";
	cin >> len;
	arr = new int[len];
	for(int i = 0;i < len;i++)	
	{
		cin >> arr[i];
		}
	if(len <= 10){
		cout << "Using insertion sort." << endl;
		insertionSort(arr,len);
		}
	else{
		cout << "Using quicksort." << endl;
	 	quickSort(arr,0,len-1);
	}
	for(int i = 0 ;i < len;i++){
		cout << arr[i] << " ";	
		}
	cout << endl;
	return 0;	
}
