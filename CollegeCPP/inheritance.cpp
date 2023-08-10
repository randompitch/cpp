#include <iostream>
#include <string>
using namespace std;

class Publication 
{
    protected : 
        string title;
        float price;

    public : 
        void getData(){
            cout << endl << "Enter title: ";
            getline(cin, title);
            cout << "Enter price: ";
            cin >> price;
        }

        void putData(){
            cout << endl << "PRINTING DETAILS:"  << endl;
            cout << "Publication title: " << title << endl;
            cout << "Price: " << price << endl;
        }
};

class Sales
{
    protected :
        float arr[3];

    public :
        void getData(){
            cout << "enter 3 sales amounts: ";
            for (int i = 0; i <= 2; i++){
                cin >> arr[i];
                cin.ignore();
            }
        }

            void putData(){
                cout << "3 Sales amount: " << endl;
                for (int i = 0; i <= 2; i++){
                    cout << arr[i] << endl;
                }            
        }
};

class book : public Publication, public Sales
{
    private :
        int pageCount;
    public :
        void getData(){
            Publication :: getData();
            cout << "Enter page count: ";
            cin >> pageCount;
            cin.ignore();
        }

        void putData(){
            Publication :: putData();
            cout << "Number of pages: " << pageCount << endl;
        }
};

class Tape : public Publication, public Sales
{
    private : 
        float playTime;

    public :
        void getData(){
            Publication :: getData();
            cout << "Enter playing time(in minutes): ";
            cin >> playTime;
            cin.ignore();
        }

        void putData(){
            Publication :: putData();
            cout << "Playing time in minutes: " << playTime << endl;
        }
};

int main()
{
    book b1;
    b1.getData();
    b1.Sales::getData();
    b1.putData();
    b1.Sales::putData();

    Tape t1;
    t1.getData();
    t1.putData();
  
    return 0;
}