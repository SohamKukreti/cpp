#include <bits/stdc++.h> 
using namespace std;

int max(int a, int b) { 
    return (a > b) ? a : b; 
} 

int max(int a, int b, int c) { 
    return max(max(a, b), c); 
} 

int maxCrossingSum(int *arr, int l,int m , int r){
	int sum = 0;
	int l_sum = INT_MIN;
	for(int i = m;i>=l;i--){
		sum+=arr[i];
		if(sum > l_sum) l_sum = sum;
	}

	sum = 0;
	int r_sum = INT_MIN;
	for(int i = m;i<=r;i++){
		sum+=arr[i];
		if(sum>r_sum) r_sum = sum;
	}

	return max(l_sum + r_sum - arr[m],l_sum,r_sum);
}

int maxSubarraySum(int *arr,int l,int r){
	if(l>r) return INT_MIN;
	if(l == r) return arr[l];
	int mid = (l + r)/2;
	return max(maxSubarraySum(arr,l,mid - 1), maxSubarraySum(arr,mid+1,r), maxCrossingSum(arr, l, mid, r));

}

int main() { 
    int arr[] = { 2, 3, 4, 5, 7 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int max_sum = maxSubarraySum(arr, 0, n - 1); 
    cout << "Maximum contiguous sum is " << max_sum; 
    return 0; 
} 
