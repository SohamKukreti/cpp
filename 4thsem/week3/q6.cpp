#include <iostream>
using namespace std;

void firstlastOcc(int *arr,int len, int x){
	int l = 0;
	int r = len - 1;
	int first = -1;
	int last = -1;
	// find first occurrence 
	while(l<r){
		int mid = (l + r)/2;
		if(arr[mid] == x){
			first = mid;
			r = mid - 1;
		}

		else if(arr[mid] > x){
			r = mid - 1;
		}
		else if(arr[mid] < x){
			l = mid + 1;
		}
	}
	//find last occurrence
	l = 0;
	r = len - 1;
	while(l<r){
		int mid = (l + r)/2;
		if(arr[mid] == x){
			last = mid;
			l = mid + 1;
		}

		else if(arr[mid] > x){
			r = mid - 1;
		}
		else if(arr[mid] < x){
			l = mid + 1;
		}
	}
	cout << "First occurrence of target is : " << first << endl;
	cout << "Last occurence of target is : " << last << endl;
}

int main(){
	int *arr;
	int len;
	cout << "Enter length of array : ";
	cin >> len;
	arr = new int[len];
	for(int i = 0;i < len;i++){
		cin >> arr[i];
		}
	cout << "Enter element you are looking for : ";
	int x;
	cin >> x;
	firstlastOcc(arr,len,x);
	return 0;
}
