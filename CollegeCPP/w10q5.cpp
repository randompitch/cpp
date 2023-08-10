#include <iostream>
using namespace std;

template <typename T> class MyVector{
        T* arr;
        int capacity;
        int curSize; 
    public :
        
        MyVector(){
            arr = new T[1];
            capacity = 1;
            curSize = 0;
        }

        int size(){
            return curSize;
        }

        void pushBack(T data){
            if(curSize == capacity){
                T* temp = new T[2 * capacity];
            for(int i = 0; i < capacity; i++){
            temp[i] = arr[i];
            }
            delete[] arr;
            capacity *= 2;
            arr = temp;
            }
            arr[curSize] = data;
            curSize++;
        }

        

        void pop(){ curSize--;}

        void print(){
            for( int i = 0; i < curSize; i++){
                cout << arr[i] << " ";
            }
        }
};

int main()
{
    MyVector<int> v1;
    MyVector<float> v2;
    MyVector<char> v3;
    cout << "Size of V1 " << v1.size() << endl;
    cout << "Size of V2 " << v2.size() << endl;
    cout << "Size of V3 " << v3.size() << endl;

    v1.pushBack(12);
    v1.pushBack(15);
    v1.pushBack(14);
    v1.pushBack(13);
    cout << endl;
    cout << "Size of V1 " << v1.size() << endl;
    cout << "Size of V2 " << v2.size() << endl;
    cout << "Size of V3 " << v3.size() << endl;
    cout << "Elements of V1: ";
    v1.print();
    cout << endl;

    v2.pushBack(12.23);
    v2.pushBack(15.23);
    v2.pushBack(14.23);
    v2.pushBack(13.23);
    
    cout << "Size of V1 " << v1.size() << endl;
    cout << "Size of V2 " << v2.size() << endl;
    cout << "Size of V3 " << v3.size() << endl;
    cout << "Elements of V2: ";
    v2.print();
    cout << endl;

    v3.pushBack(65);
    v3.pushBack(66);
    v3.pushBack(67);
    v3.pushBack(68);
    cout << "Size of V1 " << v1.size() << endl;
    cout << "Size of V2 " << v2.size() << endl;
    cout << "Size of V3 " << v3.size() << endl;
    cout << "Elements of V3: ";
    v3.print();
    cout << endl;

    v3.pop();
    cout << "Size of V1 " << v1.size() << endl;
    cout << "Size of V2 " << v2.size() << endl;
    cout << "Size of V3 " << v3.size() << endl;
    cout << "Elements of V3: ";
    v3.print();
  
    return 0;
}