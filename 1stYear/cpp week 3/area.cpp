#include <iostream>
using namespace std;
class Area{
    private:
        int l;
        int b;
    public:
        Area(){
            l = 1;
            b = 1;
            }
        Area(int x, int y){
            setDim(x,y);
            }
        void setDim(int x, int y){
            if(x > 0 && y > 0){
                l = x;
                b = y;
            }
            else{
                l = 1;
                b = 1;
            }
        }
        int getArea(){
            return l * b;
            }
    };

int main(){
    Area a1;
    a1.setDim(5,4);
    cout << a1.getArea();
    return 0;
    }
