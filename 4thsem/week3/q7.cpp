#include <iostream>
using namespace std;

int merge(int * arr, int l, int m , int r){
	int *left = new int[m-l + 1];
	int *right = new int[r - m];
	
	int leftLen = m - l  + 1;
	int rightLen = r - m;
	
	for(int i = 0;i < leftLen;i++){
		left[i] = arr[i + l];
	}

	for(int i = 0;i<rightLen;i++){
		right[i] = arr[i + m + 1];
	}

	int i = 0;
	int j = 0;
	int k  = l;
	int invCnt = 0;
	while (i < leftLen && j < rightLen){
		if(left[i] <= right[j]){
			arr[k] = left[i];
			i++;
		}
		else if(right[j] < left[i]){
			arr[k] = right[j];
			j++;
			invCnt = invCnt + (m - i + 1);
		}
		k++;
	}

	while(i < leftLen){
		arr[k] = left[i];
		i++;
		k++;
	}

	while(j < rightLen){
		arr[k] = right[j];
		j++;
		k++;
	}

	return invCnt;
	
}

int findInversions(int *arr, int l, int r){
	int invCnt = 0;
	int mid = 0;
	if(l < r){
	int mid = (l + r)/2;
	invCnt = findInversions(arr,l,mid);
	invCnt += findInversions(arr,mid+1,r);
	invCnt += merge(arr,l,mid,r);
	}
	return invCnt;
}

int main(){
	int *arr;
	int len;
	cout << "Enter size of array : ";
	cin >> len;
	arr = new int[len];
	for(int i = 0;i < len; i++){
		cin >> arr[i];
	}
	cout << findInversions(arr,0, len - 1) << endl;
	for(int i = 0;i < len; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
