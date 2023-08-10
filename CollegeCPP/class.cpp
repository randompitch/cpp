#include <iostream>
#include <string>
using namespace std;

class Student
{
    string name;
    int roll_no;

    public:
        Student(){
            name = "NULL";
            roll_no = 0;
        }

        Student(string name, int r){
            this->name = name;
            roll_no = r;
        }

        void set(){

            cout << "enter name: ";
            cin >> name;
            cout << "enter roll: ";
            cin >> roll_no;
             
        }

        void print(){
            cout << "NAME: " << name << endl << "ROLL NO:  " << roll_no << endl;
        }

};

int main()
{
    Student s1("john", 2), s2("Sam", 3), s3;
    s3.set();
    s1.print();
    s2.print();
    s3.print();
      
    return 0;
}