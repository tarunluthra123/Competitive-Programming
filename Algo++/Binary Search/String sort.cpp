/*

Nishant is very naughty boy in Launchpad Batch. One day he was playing with strings, and randomly shuffled them all. Your task is to help Nishant Sort all the strings ( lexicographically ) but if two strings have a common part, then string with longer length should come first. Eg bat ,batman are 2 strings have common part as bat - then sorted order should have - batman, bat.

Input Format:
N(integer) followed by N strings.

Constraints:
N<=1000

Output Format
N lines each containing one string.

Sample Input
3
bat
apple
batman
Sample Output
apple
batman
bat

*/


#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool myCompare(string a,string b)
{
    int found = a.find(b);
    int check = b.find(a);
    if(found!=string::npos||check!=string::npos)
    {
        return a>b;
    }
    else
    return a<b;   
}

int main() 
{
    string a[1000];
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n,myCompare);
    for(i=0;i<n;i++)
        cout<<a[i]<<endl;
    return 0;
}
