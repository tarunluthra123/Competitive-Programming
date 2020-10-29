/*
You are given an balanced expression. You have to find if it contains duplicate parentheses or not. A set of parentheses are duplicate if same subexpression is surrounded by multiple parenthesis.


Input Format:
First line contains integer t as number of test cases. Next t lines contains n expressions.

Output Format:
Print either given expression is Duplicate or Not Duplicates.

Sample Input:
2
(((a+(b))+(c+d)))
((a+(b))+(c+d))
Sample Output:
Duplicate
Not Duplicates
 
Explanation:
For 1st test case : The subexpression "(a+(b))+(c+d)" is surrounded by two pairs of brackets.
*/
#include <iostream>
#include <stack>
#include <cstring>
#define pic pair<int,char>
#define mp make_pair

using namespace std;

bool checkDuplicate(string str){
    stack<pic> s;
    for(unsigned long i=0;i<str.size();i++){
        char c = str[i];
        if(c=='('){
            pic p = mp(i,c);
            s.push(p);
        }
        else if(c==')'){
            pic p1 = s.top();
            s.pop();
            if(s.empty() || i==str.size()-1){
                continue;
            }
            pic p2 = s.top();
            if(str[i+1]==')' && p1.first-p2.first == 1){
                return true;
            }
        }
    }
    return false;
}
int main() {

    int testCases;
    cin>>testCases;
    while(testCases--){
    	string str;
        cin>>str;
        bool ans = checkDuplicate(str);
        if(ans)
            cout<<"Duplicate";
        else
            cout<<"Not Duplicates";

        cout<<endl;
    }


    return 0;
}


