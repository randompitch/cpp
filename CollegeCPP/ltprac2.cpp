#include <iostream>
#include<map>
using namespace std;

int main()
{
    int n;
    string str;
    cin>>n;
    map <string, int> user;

    while(n--){
        cin>>str;
        if(user.count(str)==0){
            cout<<"OK"<<endl;
            user[str]=1;
        }
        else{
            cout<<str<<user[str]<<endl;
            user[str]++;
        }
    }
    return 0;
}