#include <iostream>
using namespace std;
class student{
    private:
        int marks;
    public:
        student(){
            marks = 1;
            }
        student(int x)
        {
            marks = x;
        }
        float calculateAverage(student s1, student s2){
            return (s1.marks + s2.marks)/2.0;
            }
    };

int main(){
    student s1(5);
    student s2(6);
    cout << s1.calculateAverage(s1,s2);
    return 0;
    }
