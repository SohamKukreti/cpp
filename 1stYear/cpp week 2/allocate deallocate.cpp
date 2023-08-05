#include <iostream>
using namespace std;
int main(){
    int *p = new int(5);
    float *f = new float(4.7);
    cout << *p << endl;
    cout << *f;
    delete p;
    delete f;
    return 0;
    }
