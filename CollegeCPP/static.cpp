#include <iostream>
using namespace std;

void test()
{
    static int count = 0; // static variable
    cout << count ; // value is updated and // will be carried to next // function calls
    count++; 
}

int main()
{
    for (int i=0; i<5; i++)
        test();
    return 0; 
}