/*
FIBONACCI PATTERN (PATTERN 4)
Take N (number of rows), print the following pattern (for N = 4)
0
1 1
2 3 5
8 13 21 34


Constraints:
0 < N < 100
Sample Input:
4
Sample Output:
0 
1    1 
2    3     5 
8   13    21    34
Explanation:
Each number is separated from other by a tab. For given input n, You need to print n(n+1)/2 fibonacci numbers. Kth row contains , next k fibonacci numbers.
*/


#include <iostream>
using namespace std;
int main() 
{
    int a=0,b=1,c,i,j,n;
    cin>>n;
    if(n>=1)
    cout<<a<<endl;
    if(n>=2)
    {
        cout<<b<<" "<<b<<endl;
        a=1;    b=1;
    }
    for(i=3;i<=n;i++)
    {
        for(j=0;j<i;j++)
        {
            c=a+b;
            cout<<c<<" ";
            a=b;
            b=c;
        }
        cout<<endl;
    }

    return 0;
}

