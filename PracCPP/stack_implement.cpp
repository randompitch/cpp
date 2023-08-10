#include <iostream>
#include <stack>
#include <math.h>
#include <algorithm>
using namespace std;

int prefixEvaluation(string s)
{
    stack<int> st;
    for(int i = s.length()-1; i>=0; i--){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }
        else{
            int op1 = st.top();     st.pop();
            int op2 = st.top();     st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1+op2);
                break;

            case '-':
                st.push(op1-op2);
                break;
            
            case '*':
                st.push(op1*op2);
                break;

            case '/':
                st.push(op1/op2);
                break;

            case '^':
                st.push(pow(op1,op2));
                break;
 
            }
        }
    }

    return st.top();
}

int postfixEvaluation(string s)
{
    stack<int> stk;
    for(int i=0; i<s.length(); i++){
        if(s[i]>='0' && s[i]<='9'){
            stk.push(s[i]-'0');
        }
        else{
            int op2 = stk.top();        stk.pop();
            int op1 = stk.top();        stk.pop();

            switch (s[i])
            {
            case '+':
                stk.push(op1+op2);
                break;
            
            case '-':
                stk.push(op1-op2);
                break;
            
            case '*':
                stk.push(op1*op2);
                break;

            case '/':
                stk.push(op1/op2);
                break;

            case '^':
                stk.push(pow(op1,op2));
                break;

            }
        }
    }
    return stk.top();
}

int precedence(char c)
{
    if(c == '^'){
        return 3;
    }

    else if(c == '*' || c == '/'){
        return 2;
    }

    else if(c == '+' || c == '-'){
        return 1;
    }

    else{
        return -1;
    }
}

string infToPost(string s)
{
    stack<char> st;
    string res;
    for(int i=0; i<s.length(); i++){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            res+=s[i];
        }  

        else if(s[i] =='('){
            st.push(s[i]);
        }

        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                res+=st.top();
                st.pop();
            }

            if(!st.empty()){
                st.pop();
            }
        }

        else{
            while(!st.empty() && precedence(st.top()) > precedence(s[i])){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.empty()){
        res+=st.top();
        st.pop(); 
    }

    return res;
}

string infToPre(string s)
{
    reverse(s.begin(), s.end());
    stack<char> st;
    string res;
    for(int i=0; i<s.length(); i++){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            res+=s[i];
        }  

        else if(s[i] ==')'){
            st.push(s[i]);
        }

        else if(s[i] == '('){
            while(!st.empty() && st.top() != ')'){
                res+=st.top();
                st.pop();
            }

            if(!st.empty()){
                st.pop();
            }
        }

        else{
            while(!st.empty() && precedence(st.top()) >= precedence(s[i])){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.empty()){
        res+=st.top();
        st.pop(); 
    }
    reverse(res.begin(), res.end());

    return res;
}

bool balancedParanthesis(string s)
{
    stack<char> st;
    bool ans = 1;

    for(int i=0; i<s.length(); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            st.push(s[i]);
        }

        else if(s[i] == ')'){
            if(!st.empty() && st.top() == '('){
                st.pop();
            }

            else{
                ans = 0;
                break;
            }
        }

        else if(s[i] == '}'){
            if(!st.empty() && st.top() == '{'){
                st.pop();
            }

            else{
                ans = 0;
                break;
            }
        }

        else if(s[i] == ']'){
            if(!st.empty() && st.top() == '['){
                st.pop();
            }

            else{
                ans = 0;
                break;
            }
        }
    }

    if(!st.empty()){
        return false;
    }

    return ans;
}

int main()
{
    cout << prefixEvaluation("-+7*45+20") << endl;
    cout << postfixEvaluation("46+2/5*7+") << endl;
    cout << infToPost("(a-b/c)*(a/k-l)") << endl;
    cout << infToPre("(a-b/c)*(a/k-l)") << endl;
    balancedParanthesis("{([])}") ? cout << "Valid String" : cout << "Invalid String";
    return 0;
}