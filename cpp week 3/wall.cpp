#include <iostream>
using namespace std;

class Wall{
    private:
        int length;
        int height;
    public:
        Wall(int x, int y){
            length = x;
            height = y;
            }
        Wall(const Wall &t){
            length = t.length;
            height = t.height;
            }
        int area(){
            return length*height;
            }
};


int main(){
    Wall w1(5,7);
    Wall w2 = w1;
    cout << w2.area();
    return 0;
    }
