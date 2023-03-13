#include<iostream>
using namespace std;
class Base { };
class Derived: public Base {};
int main() {
Base *base_ptr = new Derived;
Derived *derived_ptr;
if(derived_ptr != NULL)

cout<<"It is working";
else
cout<<"cannot cast Base* to Derived*";
return 0;
}
