#include <iostream>
using namespace std;
int findsum(int *arr,int l,int r){
	if(l >= r){
		return arr[l];
	}
	int mid = (l + r)/2;
	return findsum(arr,l,mid) + findsum(arr,mid+1,r);

}
int main(){
	int *arr;
	int len;
	cout << "Enter the length of array : ";
	cin >> len;
	arr = new int[len];
	for(int i = 0;i< len;i++)
	{
		cin >> arr[i];
	}
	cout << findsum(arr,0,len);
	cout << endl;
	return 0;
}