#include <iostream>
using namespace std;

int findMax(int arr[], int l, int r){
	if(l >= r) return arr[l];
	int mid = (l + r)/2;
	int a = findMax(arr,l,mid);
	int b = findMax(arr,mid+1,r);
	if(a >= b) return a;
	else return b;
}

int main(){
	int arr[] = {1,2,3,4,51,6};
	cout << findMax(arr,0,5) << endl;
	return 0;
}
