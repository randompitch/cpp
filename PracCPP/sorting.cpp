#include <iostream>
using namespace std;

int main()
{
    int n,i,j,count=1;
    cout << "Enter length of array";
    cin >> n;
    
    int arr[n];
    cout << "enter elements in array :" << endl;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    /* Selection sort 
    for (i=0; i<n-1; i++){
        for (j=i+1; j<n; j++){
            if (arr[j]<arr[i]){
                int temp = arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }*/

    /*Bubble sort
    while (count<n){
        for (i=0;i<n-count;i++){
            if (arr[i]>arr[i+1]){
                int temp = arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
        count++;
    }*/

    //Insertion sort
    for(int i=1; i<n; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    for (i=0; i<n; i++){
        cout << arr[i]<<"  ";
    }
    return 0;
}