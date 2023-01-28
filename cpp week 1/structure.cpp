#include <iostream>
using namespace std;

struct employee{
    string name;
    int age;
    int sal;
    };

int main(){
    struct employee e1;
    int basic,hra,book_all,furn_all,spec_all;
    cout << "Enter Full name: ";
    getline(cin,e1.name);
    cout << "Enter age: ";
    cin >> e1.age;
    cout << "Enter salary components: ";
    cout << "Basic: ";
    cin >> basic;
    cout << "HRA: ";
    cin >> hra;
    cout << "BOOK allowance: ";
    cin >> book_all;
    cout << "Furniture allowance: ";
    cin >> furn_all;
    cout << "Special allowance: ";
    cin >> spec_all;
    e1.sal = basic + hra + book_all + furn_all+spec_all;
    cout << "Name: " << e1.name << endl;
    cout << "Age: " << e1.age << endl;
    cout << "Salary: " << e1.sal << endl;
    return 0;
    }
