#include <iostream>
using namespace std;

int factorial(int l,int r){
if(l>=r) return l;
int mid = (l + r)/2;
return factorial(l,mid) * factorial(mid+1,r);
}

int main(){
	cout << factorial(1,5) << endl;
	return 0;
}
