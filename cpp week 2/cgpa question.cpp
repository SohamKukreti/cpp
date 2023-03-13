#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    float *p = new float[n];
    for(int i = 0;i<n;i++){
        cout << "Enter CGPA of student "<< i + 1 << ": ";
        cin >> p[i];
    }
    for(int i = 0;i<n;i++){
        cout << "CGPA of student "<< i + 1 << " is " << p[i] << endl;
    }
    return 0;
    }
