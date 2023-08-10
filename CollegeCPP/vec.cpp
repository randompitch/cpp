#include <iostream>
using namespace std;

template <class T, class X> auto add(T a, X b){
    return a+b;
}

int main()
{
    cout << add(1,2.3);  
    return 0;
}