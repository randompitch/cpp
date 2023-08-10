#include <iostream>
#include <vector>
using namespace std;

class Marks
{
    vector<int> marks;
    public:
        void setMarks(){
            cout << "Enter marks of 4 students : ";
            for(int i = 0; i < 4; i++){
                int a;
                cin >> a;
                marks.push_back(a);
            }
        }

        void printNGS(){
            cout << "Mark" << "\t\t" << "NGS" << endl;
            for(int i = 0; i<marks.size(); i++){
                int next = -1;
                for(int j = i+1; j<marks.size(); j++){
                    if(marks[j] > marks[i]){
                        next = marks[j];
                        break;
                    }
                }
                cout << marks[i] << " \t--\t " << next << endl;
            }
        }

};

int main()
{
    Marks m1,m2;
    m1.setMarks();
    m1.printNGS();
    m2.setMarks();
    m2.printNGS();   
  
    return 0;
}