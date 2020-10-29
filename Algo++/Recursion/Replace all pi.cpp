/*
REPLACE ALL ?
Replace all occurrences of pi with 3.14


Input Format:
Integer N, no of lines with one string per line

Constraints:
0 < N < 1000
0 <= len(str) < 1000

Output Format:
Output result one per line

Sample Input:
3
?xpix
?xabpixx3.15x?
xpipippixx
Sample Output:
x3.14x
?xab3.14xx3.15x?
x3.143.14p3.14xx
*/


#include <iostream>
using namespace std;
void removePi(char *s)
{

    //Base case
    if(s[0]=='\0')
        return ;

    //Rec case
    if(s[0]=='p' && s[1]=='i')
    {
        cout<<"3.14";
        removePi(s+2);
    }
    else
    {
        cout<<s[0];
        removePi(s+1);
    }

}
int main()
{
    int testCases;
    cin>>testCases;
    char s[1000];
    while(testCases--)
    {
        cin>>s;
        removePi(s);
        cout<<endl;
    }

}

