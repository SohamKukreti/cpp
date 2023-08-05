#include <iostream>
using namespace std;
class customer{
    protected:
        int cid;
        string cname;
        string caddress;
    public:
        customer(){
            cid = 1;
            cname = "Unkown";
            caddress = "Unknown";
            }
        customer(int cid,string cname,string caddress){
            this -> cid = cid;
            this -> cname = cname;
            this -> caddress = caddress;
        }
    };


class savingacc : public customer{
    protected:
        int bal;
        int interest;
    public:
        savingacc(){
            bal = 0;
            interest = 0;
            }
        savingacc(int bal,int interest){
            this->bal = bal;
            this->interest = interest;
            }

        void issueInterest(){
            bal = bal + interest*bal/100;
            }

        void withdraw(int mon){
            bal -= mon;
            cout << "Money has been withdrawn" << endl;
            }
        void displayBal(){
            cout << "Your balance is : " << bal << endl;
            }
    };

class curracc : public customer{
    protected:
        int bal;
        int minBal;
        string chequeBook;
        int serviceCharge;
    public:
        curracc(){
            bal = 0;
            minBal = 0;
            chequeBook = "Unknown";
            serviceCharge = 0;
            }
        curracc(int bal, int minBal,string chequeBook,int serviceCharge){
            this->bal = bal;
            this->minBal = minBal;
            this->chequeBook = chequeBook;
            this->serviceCharge = serviceCharge;
            }
        void issueCheque(string accno,int amt){
                if(bal-amt < 0){
                    cout<< "Cheque cannot be issued" << endl;
                }
                else{
                    bal -= amt;
                    if(bal<minBal){
                        bal-=serviceCharge;
                    }
                    cout << "Cheque has been issued to " << accno << " For amount " << amt << endl;
                }

            }
        void depositCheque(string accno,int amt){
                bal+=amt;
                cout << "Cheque has been deposited to your account" << endl;
            }
        void displayBal(){
            cout << "Your account balance is : " << bal << endl;
            }
    };




int main(){
    savingacc s1(10000,5);
    s1.issueInterest();
    s1.withdraw(5000);
    s1.displayBal();
    curracc c1(15000,10000,"A3R9Z",500);
    c1.issueCheque("B0515",7000);
    c1.displayBal();

    }
