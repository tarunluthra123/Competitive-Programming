/*
PASCAL TRIANGLE
Given an integer N, print Pascal Triangle upto N rows.
Input Format:
Single integer N.

Constraints:
N <= 10

Output Format:
Print pascal triangle.

Sample Input:
4
Sample Output:
           1
         1   1
       1   2   1
     1   3   3   1
*/


#include <iostream>
using namespace std;
int value(int a,int b)
{
    if(a==0||b==0||a==b)
    return 1;
    else
    return value(a-1,b-1)+value(a-1,b);
}
int main() 
{
    int n,i,j,space;
    cin>>n;
    space = 2*n-1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<space;j++)
        cout<<" ";
        space-=2;
        for(j=0;j<=i;j++)
        {
            cout<<value(i,j)<<"   ";
        }
        cout<<endl;
    }

    return 0;
}
