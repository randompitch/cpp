#include <iostream>
using namespace std;

class Time
{
    int hours, minutes, seconds;
    public:
        Time(){
            hours = 0;
            minutes = 0;
            seconds = 0;
        }

        Time(int h, int m, int s){
            hours = h;
            minutes = m;
            seconds = s;
        }
        
        void getTime(){
            cout << "Enter time: " << endl;
            cout << " hours: ";    cin >> hours;
            cout << " minutes: ";    cin >> minutes;
            cout << " seconds: ";    cin >> seconds;
        }

        void putTime(){
            cout << endl << "Time after addition: " << hours << " : "
                 << minutes << " : " << seconds << endl;  
        }

        Time addTime(Time t1, Time t2){
            Time temp;
            temp.seconds = t1.seconds + t2.seconds;
            temp.minutes = t1.minutes + t2.minutes + (temp.seconds/60);
            temp.hours = t1.hours + t2.hours + (temp.minutes/60);
            temp.minutes %= 60;
            temp.seconds %= 60;
            return temp;
        }
};

int main()
{
    Time T1, T2, T3;
    T1.getTime();
    T2.getTime();
    T3 = T1.addTime(T1,T2);
    T3.putTime();        
  
    return 0;
}