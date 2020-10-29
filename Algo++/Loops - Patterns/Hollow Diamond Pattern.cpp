/*
Take N (number of rows), print the following pattern (for N = 5).

     * * * * *
     * *   * *
     *       *
     * *   * *
     * * * * *

Constraints:
0 < N < 10 (where N is an odd number)
*/

#include <iostream>
using namespace std;
int main() 
{
    int n,i,j,space;
    cin>>n;
    space=n/2+1;
    //cout<<space;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {   
            if(i==0||j==0||i==n-1||j==n-1||j<space||j>=n-space)
            cout<<"* ";
            else
            cout<<"  ";
        }
        cout<<endl;
        if(i<n/2)
        space--;
        else
        space++;
    }
    return 0;
}
