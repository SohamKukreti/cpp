#include <iostream>
using namespace std;
void hail(int num){
if(num==1){
return;
}
if(num%2==0){
num=num/2;
}
else{
num=(3*num)+1;
}
cout<<num<<" ";
hail(num);
}
int main()
{
int num;
cin>>num;
cout<<num<<" ";
hail(num);
return 0;
}