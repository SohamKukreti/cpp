#include <iostream>
using namespace std;
class Second{
    private:
        int personid;
    public:
    Second(){
        personid = 1;
        }
    Second(int x){
        personid = x;
        }
    int getPersonId(){
        return personid;
        }
    };

int main(){
    Second obj1;
    Second obj2(5);
    cout << obj1.getPersonId() << endl;
    cout << obj2.getPersonId();
    return 0;
    }
