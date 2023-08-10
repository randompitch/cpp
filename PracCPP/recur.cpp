#include <iostream>
using namespace std;
/*ABC
    s= ABC ros = BC; ch = 'A' ans = ""
    s= BC ros = C;  ch = 'B' ans = ""
    s= C ros = ;   ch = 'C' ans = ""
    s= "";

*/
void subSeq(string s, string ans)
{
    if (s.length()==0){
        cout << ans << endl;
        return;
    }    
    char ch = s[0];
    string ros = s.substr(1);

    subSeq(ros, ans);
    subSeq(ros, ans+ch);
}

int main()
{
    subSeq("ABC", "");
        
    return 0;
}