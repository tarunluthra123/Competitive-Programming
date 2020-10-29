/*
RECURSION-DUPLICATE CHARACTER FORMATTING
Take as input str, a string. Write a recursive function which returns a new string in which all duplicate consecutive characters are separated by a ‘ * ’. E.g. for “hello” return “hel*lo”. Print the value returned


Input Format:
Enter a String

Constraints:
None

Output Format:
Display the resulting string (i.e after inserting (*) b/w all the duplicate characters)

Sample Input:
hello
Sample Output:
hel*lo
*/
#include <iostream>
using namespace std;

string formatDuplicate(string s){
    if(s.size() == 1){
        return s;
    }


    string ans = "";
    ans += s[0] ;
    if(s[0] == s[1]){
        ans += "*" ;
        ans += formatDuplicate(s.substr(1,s.size()-1));
        return ans;
    }


    ans += formatDuplicate(s.substr(1,s.size()-1));
    return ans;
}

int main() {
    string s ;
    cin >> s; 

    cout << formatDuplicate(s);

    return 0;
}

