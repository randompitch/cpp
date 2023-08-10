#include <iostream>
#include <string>
using namespace std;
class Box
{
    int capacity;
    public:
        Box(){};

        Box(double capacity){
        this->capacity = capacity;
        }

        bool operator < (Box b){
            if (this->capacity < b.capacity){
                return true;
            }
            else { return false;}
        }

        int operator + (Box b){
            return (this->capacity + b.capacity);
        }

};

int main(int argc, char const *argv[])
{
    Box b1(10);
    Box b2 = Box(1);
    if (b1 < b2){
        cout<<"Box 2 has large capacity." << endl;
    }
    else{
        cout<<"Box 1 has large capacity." << endl;
    }

    cout << "Capacity of both boxes : " << b1+b2;


    
    return 0;
}