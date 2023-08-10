#include <iostream>
#include <vector> 
using namespace std;
vector<int> lcm;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void findlcm(int arr[], int n)
{
    long long int ans = arr[0];
    for (int i = 1; i < n; i++)
        ans = (((arr[i] * ans)) / (gcd(arr[i], ans)));
    lcm.push_back(ans);
}

void makeNewArr(int a[], int b[], int n, int k){
    int newArr [n];
    for (int i = 0; i <= k; i++)
    {
        newArr[i] = a[i];
    }
    for (int i = k; i < n; i++)
    {
        newArr[i] = b[i];
    }
    findlcm(newArr, n);
}
int test()
{
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    for(int i = 0; i <n; i++){
        makeNewArr(a,b,n,i);
    }

    int max = lcm[0];
    for (int i = 1; i < lcm.size(); i++)
    {
        if(lcm[i] >  max){
            max = lcm[i];
        }
    }
    
    cout << max << endl;  

    return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--){
        test();
    }
 
    return 0;
}