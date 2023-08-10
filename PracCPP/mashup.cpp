#include <iostream>
using namespace std;

int main(){ 
int n;  
cin >> n;
double res{0};
for(int i = n; n > 0; n--){
    res += 1. / n;
    cout << res;
}
return 0;
}
