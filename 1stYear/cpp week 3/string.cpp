#include <iostream>
#include <string.h>
using namespace std;

class String{
    private:
        char *s;
        int size;

    public:
        String(){
            size = 1;
            s = new char[size];
            }
        String(char *p,int x){
            size = x;
            s = new char[size];
            strcpy(s,p);

            }
        String(const String &t){
            size = t.size;
            s = new char[size];
            strcpy(s,t.s);

            }

         void display(){
            cout << s << endl;
            }

        ~String(){
            cout << "Destructor initialized" << endl;
            delete s;
            }
    };


int main(){
    char *s = "soham";
    String s1(s,5);
    String s2 = s1;
    s2.display();
    return 0;
    }
