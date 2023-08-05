#include <iostream>
using namespace std;

class bankAccount{
    private:
        int accno;
        string name;
        char typeOfAcc;
        int bal;
    public:
        bankAccount(int accno,string name, char typeOfAcc,int bal){
                this->accno = accno;
                this->name = name;
                this->typeOfAcc = typeOfAcc;
                this->bal = bal;
            }
         bankAccount(){
                this->accno = 1;
                this->name = "Unknown";
                this->typeOfAcc = 'S';
                this->bal = 0;
            }
        void withdrawMoney(int amt){
            if(bal-amt < 1000){
                cout << "Cannot withdraw money";
            }
            else{
                cout << "Money has been withdrawn" << endl;
                bal -= amt;
            }
        }

        void depositMoney(int amt){
            bal+=amt;
            cout << "Amount has been deposited." << endl;
            }
        void display(){
            cout << accno << endl;
            cout << name << endl;
            cout << typeOfAcc << endl;
            cout << bal << endl;
            }



    };

int main(){
    bankAccount b1(1,"Rakesh Kumar",'S',10000);
    b1.withdrawMoney(5000);
    b1.depositMoney(2000);
    b1.display();

    return 0;
    }
