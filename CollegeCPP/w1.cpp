#include <iostream>
using namespace std;

struct phone
{
    int price, batPow;
    float rating;

}p1, p2;

int main()
{
    cout << "Enter phone 1 details:" << endl;
    cout << "Price: "; cin >> p1.price;
    cout << "Enter Battery Power (in mAh): "; cin >> p1.batPow;
    cout << "Enter Rating(between 0-5): "; cin >> p1.rating;
    cout << "Enter phone 2 details:" << endl;
    cout << "Price: "; cin >> p2.price;
    cout << "Enter Battery Power (in mAh): "; cin >> p2.batPow;
    cout << "Enter Rating(between 0-5): "; cin >> p2.rating;

    if(p1.price < p2.price){
        cout << "Phone better wrt Price is Phone 1." << endl;
    } 
    else {cout << "Phone better wrt Price is Phone 2." << endl;}

    if(p1.batPow > p2.batPow){
        cout << "Phone better wrt Battery Power is Phone 1." << endl;
    }
    else {cout << "Phone better wrt Battery Power is Phone 2." << endl;}
    
    if(p1.rating > p2.rating){
        cout << "Phone better wrt Rating is Phone 1." << endl;
    }
    else {cout << "Phone better wrt Rating is Phone 2." << endl;}
  
    return 0;
}