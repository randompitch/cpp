#include <iostream>
#include <vector>
using namespace std;

void countSort(int arr[], int n)
{
    int k = arr[0];
    for(int x=0; x<n; x++){
        k = max(k,arr[x]);

    }

    vector<int> count(k+1, 0);
    for(int i=0; i<n; i++){
        count[arr[i]]++;
    }

    for(int i=1; i<=k; i++){
        count[i] += count[i-1];        
    }

    int output[n]; 
    for(int i = n-1; i >=0; i--){
        output[--count[arr[i]]] = arr[i];
    }

    for(int i=0; i<n; i++){
        arr[i] = output[i];
    }
    
}

int main()
{ 
    int arr[] = {1,4,1,2,7,5,2};
    countSort(arr, 7);
   
    for(int i =0; i<7; i++){
        cout << arr[i] << " ";
    }
    return 0;
}