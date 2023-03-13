#include <iostream>
using namespace std;
class Time{
    private:
        int h,m,s;
    public:
        Time(){
            h = 1;
            m = 0;
            s = 0;
            }
        Time(int x,int y,int z){
            h = x;
            m = y;
            s = z;
            }
        bool operator==(Time t2){
            if(h == t2.h && m == t2.m && s == t2.s){
                return true;
            }
            else{
                return false;
            }
        }
        friend ostream &operator<<(ostream &output,Time t1);
        friend istream &operator>>(istream &input,Time &t1);
        bool operator<(Time t2){
            if(h<t2.h) return true;
            else if(m<t2.m) return true;
            else if(s<t2.s) return true;
            else return false;
        }
        bool operator>(Time t2){
            if(h>t2.h) return true;
            else if(m>t2.m) return true;
            else if(s>t2.s) return true;
            else return false;
        }
        Time operator()(int a){
            Time t;
            t.h = a*10;
            t.m = a*3;
            t.s = a*2;
            return t;
            }
    };


ostream &operator<<(ostream &output,Time t1){
            output << t1.h  << " " << t1.m << " " << t1.s << endl;
            return output;
            }



istream &operator>>(istream &input,Time &t1){
    input >> t1.h >> t1.m >> t1.s;
    return input;
    }





int main(){
    Time t1(2,4,6);
    Time t2;
    cout << t1;
    cin >> t2;
    if(t1 == t2){
        cout << "They are the same";
    }
    else{
        if(t1>t2){
            cout << "t1";
        }
        else if(t1<t2){
            cout << "t2";
        }
    Time t3 = t2(10);
    cout << t3;
    }
    }
