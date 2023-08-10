#include <iostream>
using namespace std;

void merge(int arr[], int l, int high, int mid)
{
    int n1 = mid-l+1, n2 = high-mid;
    int left[n1], right[n2];
    for(int i = 0; i<n1; i++){
        left[i] = arr[l+i];
    }
    for(int j = 0; j<n2; j++){
        right[j] = arr[mid+j+1];
    }
    int i{0}, j{0}, k{0};
    while(i<n1 && j<n2){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i++;
            k++;
        }
        else{
            arr[k] = right[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        arr[k] = left[i];
        k++;    i++; 
    }
    while(j<n2){
        arr[k] = right[j];
        j++;    k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if(r>l){
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr,l,r,m);
    }
}

int main()
{
    int arr[] = {2,5,9,1,3,0,8,4,6,7};
    cout << "Before Sorting: ";
    for(int i =0; i<10; i++){
        cout << arr[i] << " ";
    }
    mergeSort(arr, 0, 9);
    cout << "\nAfter Sorting: ";
    for(int i =0; i<10; i++){
        cout << arr[i] << " ";
    }

  
    return 0;
}