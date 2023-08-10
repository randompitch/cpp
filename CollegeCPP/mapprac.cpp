#include <iostream>
#include <map>
#include <iterator>
using namespace std;

int main()
{
    map<string,int> m;
    int q;
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        string x;
        int y;
        if(type == 1){
            cout << "Enter name: "; cin >> x;
            cout << "Enter number: "; cin >> y;
            if(m.count(x)>0){
                m[x]+=y;
            }
            else{m[x]=y;}
        }

        else if(type == 2){
            cout << "Enter name: "; cin >> x;
            m[x]=0;

        }

        else{
            cout << "Enter name: "; cin >> x;
            map<string,int>::iterator it=m.find(x);
            cout << "Marks of: " << it->first << " are " << it->second << endl;
                        
        }
    }
  
    return 0;
}