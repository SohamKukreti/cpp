#include <iostream>
using namespace std;
int main(){
    int x,y,z;
    cout << "Enter 3 numbers: ";
    cin >> x;
    cin >> y;
    cin >> z;
    int sum = x + y + z;
    int avg = sum/3;
    cout << "Sum is " << sum << endl;
    cout << "Average is " << avg;
    return 0;
    }
