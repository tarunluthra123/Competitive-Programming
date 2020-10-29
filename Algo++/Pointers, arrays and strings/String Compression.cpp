/*

STRING COMPRESSION
Take as input S, a string. Write a function that does basic string compression. Print the value returned. E.g. for input “aaabbccds” print out a3b2c2d1s1.


Input Format:
A single String S

Constraints:
1 < = length of String < = 100 
Output Format:
The compressed String.

Sample Input:
aaabbccds
Sample Output:
a3b2c2d1s1

*/

#include <iostream>
#include <cstring>
using namespace std;
int main() 
{
    char s[1000];
    cin>>s;
    int i,j,c;
    for(i=0;i<strlen(s);i++)
    {   
        cout<<s[i]; c=0;
        for(j=i;s[j]==s[i];j++)
        c++;
        cout<<c;
        i=i+c-1;
    }
    return 0;
}

