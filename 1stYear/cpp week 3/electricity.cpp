#include <iostream>
using namespace std;
class customer{
    private:
        int cno;
        string cname;
        int unitsConsumed;

    public:

        void getCno(int x){
            cno = x;
            }

        void getCname(string s){
            cname = s;
            }

        void getUnitsConsumed(int x){
            unitsConsumed = x;
            }

        int calc_bill(){
                int price = 10;
                return unitsConsumed*price;
            }

        void putCustomer(){
            cout << cno << " : " << cname << " : " << calc_bill();
            }
    };



int main(){
    customer c1;
    c1.getCname("Raj Kumar");
    c1.getCno(1);
    c1.getUnitsConsumed(50);
    c1.putCustomer();
    return 0;
    }
