/*
RECURSION-CONVERT STRING TO INTEGER
Take as input str, a number in form of a string. Write a recursive function to convert the number in string form to number in integer form. E.g. for “1234” return 1234. Print the value returned.

Input Format:
Enter a number in form of a String

Constraints:
None

Output Format
Print the number after converting it into integer

Sample Input
1234
Sample Output
1234
*/
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int convert(char* s,int n)
{
    if(n==1)
        return s[0]-'0';
    
    return (s[0]-'0')*pow(10,n-1) + convert(s+1,n-1);
}

int main() 
{
    char *s = new char;
    cin>>s;
    int n= strlen(s);
    cout<<convert(s,n);
    return 0;
}
