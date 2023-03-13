#include <iostream>
using namespace std;


class sales{
    protected:
        float sales[3];
    public:
        getData(float sale1,float sale2,float sale3){
                sales[0] = sale1;
                sales[1] = sale2;
                sales[2] = sale3;
            }
        putData(){
            for(int i = 0;i<3;i++){
                cout << sales[i] << " ";
            }
            cout << endl;
            }
};


class publication{
    protected:
        string title;
        float price;
    public:
        void getData(string title,float price){
                this -> title = title;
                this -> price = price;

            }
        void putData(){
            cout << title << endl;
            cout << price << endl;
            }
    };
class book : public publication,public sales {
    protected:
        int pgCount;
    public:
        void getData(string title,float price,int pgCount,float sale1,float sale2,float sale3){
                this -> title = title;
                this -> price = price;
                this -> pgCount = pgCount;
                sales[0] = sale1;
                sales[1] = sale2;
                sales[2] = sale3;
            }
        void putData(){
            cout << title << endl;
            cout << price << endl;
            cout << pgCount << endl;
            for(int i = 0;i<3;i++){
                cout << sales[i] << " ";
            }
            cout << endl;
            }
    };

class tape : public publication,public sales{
    protected:
       float playTime;
     public:
        void getData(string title,float price,int playTime,float sale1,float sale2,float sale3){
                this -> title = title;
                this -> price = price;
                this -> playTime = playTime;
                sales[0] = sale1;
                sales[1] = sale2;
                sales[2] = sale3;
            }
        void putData(){
            cout << title << endl;
            cout << price << endl;
            cout << playTime << endl;
            for(int i = 0;i<3;i++){
                cout << sales[i] << " ";
            }
            cout << endl;
            }

    };



int main(){
    book b1;
    tape t1;
    b1.getData("Harry Potter",349,200,100,200,300);
    t1.getData("Atomic Habits",299,210,100,200,300);
    t1.putData();
    }
