#include <iostream>
#include <vector>
using namespace std;

void rev(vector<int> &v)
{
    int start = 0, end = v.size()-1;
    while(start <= end){
        swap(v[start], v[end]);
        start++;
        end--;
    }
}

int main()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    for(int i = 0; i < v1.size(); i++){
        cout << v1[i] << " ";
    }
    cout << endl;
    rev(v1);
    for(int i = 0; i < v1.size(); i++){
        cout << v1[i] << " ";
    }
    cout << endl;

    vector<int> v2;
    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(30);
    v2.push_back(40);
    v2.push_back(50);
    for(int i = 0; i < v2.size(); i++){
        cout << v2[i] << " ";
    }
    cout << endl;
    rev(v2);
    for(int i = 0; i < v2.size(); i++){
        cout << v2[i] << " ";
    }
  
    return 0;
}