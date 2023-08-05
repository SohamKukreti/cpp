#include <iostream>
using namespace std;
class account{
    protected:
        int accno;
        string cname;
        string acctype;
    public:

        setAccno(int accno){
            this->accno = accno;
            }

        setCname(string cname){
            this->cname = cname;
            }

        setacctype(string acctype){
            this->acctype = acctype;
            }

    };


class sav_acct : public account{
    protected:
        int bal;
        int interest;
    public:
        setBal(int a){
            bal = a;
            }
        setInterest(int i){
            interest = i;
            }

        void computeInterest(){
            cout << "Your interest is: " << interest*bal/100;
            }

        void depositInterest(){
            bal = bal + interest*bal/100;
            }
        void deposit(int mon){
            bal+=mon;
            cout << "Money has been deposited" << endl;
            }
        void withdraw(int mon){
            bal -= mon;
            cout << "Money has been withdrawn" << endl;
            }

        void displayBal(){
            cout << "Your balance is : " << bal << endl;
            }
    };

class curr_acct : public account{
    protected:
        int bal;
        int minBal;
        int serviceCharge;
    public:
        void setBal(int a){
            bal = a;
            }
        void setMinBal(int a){
            minBal = a;
            }
        void setServiceCharge(int a){
            serviceCharge = a;
            }
        void depositMoney(int a){
            bal+=a;
            cout << "Deposited money" << endl;
            }
        void withdrawMoney(int a){
            if(bal - a < 0){
                cout << "Cannot withdraw money";
            }
            else{
                bal-=a;
                checkMinBal();
            }
            }
        void checkMinBal(){
            if(bal < minBal){
                cout << "Your balance is lower than minimum balance, imposing penalty." << endl;
                bal -= serviceCharge;
            }
            while(bal<minBal){
                int a;
                cout << "Enter amount to deposit in your account: ";
                cin >> a;
                depositMoney(a);
            }

            }

        void displayBal(){
            cout << "Your account balance is : " << bal << endl;
            }
    };




int main(){
    sav_acct s1;
    curr_acct c1;
    s1.setAccno(1);
    s1.setCname("Soham");
    s1.setBal(1000);
    s1.deposit(5000);
    s1.displayBal();
    c1.setAccno(1);
    c1.setacctype("Current");
    c1.setBal(10000);
    c1.setMinBal(9000);
    c1.setServiceCharge(100);
    c1.withdrawMoney(2000);
    c1.displayBal();
    }
