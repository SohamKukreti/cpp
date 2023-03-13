#include <iostream>
#include <string.h>
using namespace std;
class student{
    private:
        int enrolno;
        string name;
        string branch;
        float cgpa;
    public:

        student(){
            enrolno = 1;
            name = "Unknown";
            branch = "CSE";
            cgpa = 6;
            }

        student(int x,string sname, string sbranch, float scgpa)
        {
            enrolno = x;
            name = sname;
            branch = sbranch;
            cgpa = scgpa;
        }

        student(int x,string sname, float scgpa){
            enrolno = x;
            name = sname;
            branch = "CSE";
            cgpa = scgpa;
        }

        void setEnrolno(int x){
             enrolno = x;
            }

        void setName(string sname){
             name = sname;
            }

        void setBranch(string sbranch){
             branch = sbranch;
            }

        void setCgpa(float scgpa){
            cgpa = scgpa;
            }

        int getEnrolno(){
             return enrolno;
            }

        string getName(){
             return name;
            }

        string getBranch(){
             return branch;
            }

        float getCgpa(){
            return cgpa;
            }
    };


int main(){
    student s1;
    student s2(2,"Soham Kukreti","CSE",9.1);
    student s3(3,"Mukesh Sharma",8.7);
    cout << s3.getBranch() << endl;
    s3.setBranch("ECE");
    cout << s3.getName() << " " <<  s3.getCgpa() << " " << s3.getEnrolno() << " " << s3.getBranch();

    return 0;
    }
