#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector <int> v1(10, 0);
    for(int i = 0;i<10;i++){
        cin >> v1[i];
    }
    sort(v1.begin(), v1.end());
    for(int i = 0;i<10;i++){
        cout << v1[i] << " ";
    }
    cout << endl;
}