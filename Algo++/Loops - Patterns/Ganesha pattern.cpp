/*
 GANESHA'S PATTERN
Take as input N, an odd number (>=5) . Print the following pattern as given below for N = 7.

*  ****
*  *
*  *
*******
   *  *
   *  *
****  *

Input Format:
Enter value of N ( >=5 )

Constraints:
N >= 5
Sample Input:
7
Sample Output:
*  ****
*  *
*  *
*******
   *  *
   *  *
****  *
Explanation:
Catch the pattern for the corresponding input and print it accordingly.

*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i,j,mid;
    mid=n/2;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if((i>=0&&i<=mid&&j==0)||(i==0&&j>=mid)||(i==mid)||(j==mid)||(i==n-1&&j>=0&&j<=mid)||(j==n-1&&i>=mid))
            cout<<"*";
            else
            cout<<" ";

        }
        cout<<endl;

    }


    return 0;
}

