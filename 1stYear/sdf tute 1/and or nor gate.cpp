#include <iostream>
using namespace std;
int main(){
    cout << "INPUT:  1,1    1,0    0,1      0,0 " << endl;
    cout << "AND " << '\t' << (1&&1) << '\t' <<  (1&&0) << '\t' << (0&&1) << '\t' << (0&&0) <<endl;
    cout << endl;
    cout << "INPUT:  1,1    1,0    0,1      0,0 " << endl;
    cout << "OR " << '\t' << (1||1) << '\t' << (1||0) << '\t' << (0||1) << '\t' << (0||0) << endl;
    cout << endl;
    cout << "INPUT:  1\t0" << endl;
    cout << "NOT " << '\t' << (!1) << '\t' << (!0);

    return 0;
    }
