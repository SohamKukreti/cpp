#include <iostream>
using namespace std;
int main(){
    int x,y;
    cout << "Enter 2 numbers: ";
    cin >> x >> y;
    while(true){
        char ch;
        cout << "Enter operation: "<<endl;
        cout << "1. Addition(+)" << endl;
        cout << "2. Subtraction(-)" << endl;
        cout << "3. Multiplication(*)" << endl;
        cout << "4. Division(/)" << endl;
        cout << "5. Remainder(%)" << endl;
        cin >> ch;
        switch(ch){
            case '+':
                cout << x << '+' << y << " = " << x + y;
                break;
            case '-':
                cout << x << '-' << y << " = " << x - y;
                break;
            case '*':
                cout << x << '*' << y << " = " << x * y;
                break;
            case '%':
                cout << x << '%' << y << " = " << x % y;
                break;
            case '/':
                cout << x << '/' << y << " = " << (float)x / (float)y;
                break;
            default:
                cout << "Wrong input.";
                break;
            }
            char choice;
            cout << endl << "Do you wish to perform more arithmetic operations?(Y/N): ";
            cin >> choice;
            if(choice == 'N' or choice == 'n') break;
    }


    return 0;
    }
