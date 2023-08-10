#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v1;
    vector<int> v2;
    int i{};
    cout << "Enter elements of vector 1: ";
    while( i >= 0 ){
        cin >> i;
        if (i<0) 
            break;
        v1.push_back(i);
    }
    
    cout << "Enter elements of vector 2: ";
    int j{};
    while( j >=0 ){
        cin >> j;
        if (j<0) 
            break;
        v2.push_back(j);
    }
    
    for(int a = 0; a<v2.size(); a++){
        int b;
        for(b = 0; b<v1.size(); b++)
            if(v2[a]==v1[b]) 
                break;
        
        if(b == v1.size()){
            v1.push_back(v2[a]);
        }
    }

    sort(v1.begin(), v1.end());
    /*for(int i = 0; i <=v1.size(); i++){
        for(int j = i+1; j <= v1.size()-1; j++){
            if(v1[j] < v1[i]){
                int temp = v1[j];
                v1[j] = v1[i];
                v1[i] = temp;
            }
        }
    }*/ 
    cout << "First array after insertion in sorted form : ";
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
  
    return 0;
}
