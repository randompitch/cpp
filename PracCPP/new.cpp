/*Count zeros in a row wise and column wise sorted matrix

Given a N x N binary matrix (elements in matrix can be either 1 or 0) 
where each row and column of the matrix is sorted in ascending order, 
count number of 0s present in it.
Expected time complexity is O(N).
*/

#include <iostream>
using namespace std;

int main()
{
    int n; cin >> n;
    int matrix[n][n];
    for(int i =0; i <n; i++){
        for(int j=0; j<n; j++){
            cin >> matrix[i][j];
        }
    }
    int count{0};

    
    for(int i =0; i <n; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] == 0)
            count++;
            else 
            continue;
        }
    }

    cout << count;  
    return 0;
}