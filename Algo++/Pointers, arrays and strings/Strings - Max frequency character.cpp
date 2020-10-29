/*
TRINGS-MAX FREQUENCY CHARACTER
Take as input S, a string. Write a function that returns the character with maximum frequency. Print the value returned.


Input Format:
String

Constraints:
A string of length between 1 to 1000.
Output Format:
Character

Sample Input:
aaabacb
Sample Output:
a
*/
#include <iostream>
#include <cstring>
using namespace std;
int main() 
{
    char s[1000],ch;
    cin>>s;
    int i,j,l=strlen(s);
    int count=0,maxCount=0;
    for(i=0;i<l;i++)
    {  
        count=0;
        for(j=i;j<l;j++)
        {
            if(s[j]==s[i])
            count++;
        }
        if(count>maxCount)
        {
            maxCount=count;
            ch=s[i];
        }
    }
    cout<<ch;
    return 0;
}

