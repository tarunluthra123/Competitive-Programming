/*
You are given a string of '(' and ')'. You have to check whether the sequence of parenthesis is balanced or not. For example, "(())", "(())()" are balanced and "())(", "(()))" are not.


Input Format:
A string of '(' , ')' , '{' , '}' and '[' , ']' .

Constraints:
1<=|S|<=10^5

Output Format:
Print "Yes" if the parenthesis are balanced and "No" if not balanced.

Sample Input:
(())
Sample Output:
Yes
*/
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

bool balancedParenthesis(string str){
    stack<char> s;
    for(unsigned long i=0;i<str.size();i++){
        char c = str[i];
        if(c=='(' || c=='{' || c=='['){
            s.push(c);
        }
        else if(c==')'){
            if(s.empty() || s.top()!='('){
                return false;
            }
            s.pop();
        }
        else if(c=='}'){
            if(s.empty() || s.top()!='{'){
                return false;
            }
            s.pop();
        }
        else if(c==']'){
            if(s.empty() || s.top()!='['){
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}
int main() {
    string str;
    getline(cin,str);
    bool ans = balancedParenthesis(str);
    if(ans)
        cout<<"Yes";
    else   
        cout<<"No";

    return 0;
}

