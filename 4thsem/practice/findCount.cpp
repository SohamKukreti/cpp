#include <iostream>
using namespace std;

int findCount(int arr[],int l,int r, int x){
	if(l>=r){
		if(arr[l] == x) return 1;
		else return 0;
	}
	int mid = l + (r - l)/2;
	return findCount(arr,l,mid, x) + findCount(arr,mid+1,r,x);
}

int main(){
	int arr[] = {1,4,2,3,4,51,6,4};
	cout << findCount(arr,0,7,4) << endl;
	return 0;
}
