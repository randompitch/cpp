#include <iostream>
using namespace std;

const int minBal = 200;

class account
{
    public:
        string custName;
        int accNo, balance, amt;

        void getdata(){
            cout << "Enter the following details:" << endl;
            cout << "1. Customer name: ";                                                 cin >> custName;
            cout << "3. Account Number: ";                                                cin >> accNo;
            cout << "4. Balance: ";                                                       cin >> balance;
            
        }

        void withdraw(){
            cout << "Enter amount to withdraw: ";
            cin >> amt;
            if (amt > balance){ cout << "insufficient balance, can't withdraw," << endl;}
            else{balance -= amt;}
            display();
        }

        void deposit(){
            cout << "Enter amount to be deposited: ";
            cin >> amt;
            balance += amt;
            display();
        }

        void display(){
            cout << "The account balance is: " << balance << endl;
        }

};

class cur_acct: public account
{
    int cheque;
    public:
        void chkBal(){
            if (balance < minBal){
                imposePenalty();
            } 
        }

        void imposePenalty(){
            cout << "You have been penalised Rs.20 for not keeping minimum balance.";
            balance -= 20;
            display();
        }

};

class sav_acct : public account
{
    public :
        void interest()
        {
            int t;
            cout<<"\nEnter time interval in year:";
            cin>>t;
            balance=balance*(1+2*t);
            display();
        }
};


int main()
{
    sav_acct s1;
    cur_acct c1;
    s1.getdata();
    s1.display();
    s1.withdraw();
    s1.interest();
    s1.deposit();
    c1.getdata();
    c1.chkBal();
    c1.deposit();
    c1.withdraw();
    c1.chkBal();

    return 0;
}