#include <iostream>
using namespace std;

void Seive(int n)
{
    int prime[100]={0};
    
    for(int i=2; i<=n; i++){
        if (prime[i]==0){
            for (int j = i*i; j<=n; j+=i){
                prime[j]=1;
            }
        }
    }

    for(int i=2; i<=n; i++){
        if (prime[i]==0){
            cout << i << " ";
        }
    }
    cout << endl;
    
}

void pFactor(int n)
{
    int spf[100]={0};
    
    for (int i=2; i<=n; i++){
        spf[i]=i;
    }

    for (int i=2; i<=n; i++){
        if (spf[i]==i){
            for (int j= i*i; j<=n; j+=i){
                if (spf[j]=j){
                    spf[j]=i;
                }
            }
        }
    }

    while(n!=1){
        cout << n << endl;
        n=n/spf[n];
    }

}

int main()
{
    int n,t;
    cin >> n >> t ;
    Seive(n);
    pFactor(t);
    cout << "DONE";
    return 0;
}