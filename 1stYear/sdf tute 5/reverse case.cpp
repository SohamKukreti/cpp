#include <iostream>
using namespace std;
class A{
    public:
        string str;
        A(){
            str = "Soham";
            }
        A(string s1){
            str = s1;
            }
        string operator!(){
            string s1;
            for(int i = 0;str[i]!='\0';i++){
                if(str[i]>=65 && str[i] <= 92){
                    s1 += (str[i] += 32);
                }
                else if(str[i]>=93){
                    s1 += (str[i] -= 32);
                }
            }
            return s1;
            }
    };

int main(){
    A a1("RajkuZar");
    cout << !a1;
    return 0;
    }
