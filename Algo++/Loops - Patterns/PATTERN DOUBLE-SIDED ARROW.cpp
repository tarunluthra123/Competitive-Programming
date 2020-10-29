/*
Take N as input. For a value of N=7, we wish to draw the following pattern :

                            1 
                        2 1   1 2 
                    3 2 1       1 2 3 
                4 3 2 1           1 2 3 4 
                    3 2 1       1 2 3 
                        2 1   1 2 
                            1 
Input Format:
Take N as input.

Constraints:
N is odd number.
*/

#include <iostream>
using namespace std;
int main() 
{
    int n,i,j,x;
    cin>>x;
    n=x/2+1;
    int match=0,space = x-1;
    int gap=-1;
    for(i=1;i>=1;)
    {
        for(j=0;j<space;j++)
        cout<<"  ";
        for(j=i;j>=1;j--)
        cout<<j<<" ";
        for(j=0;j<gap;j++)
        cout<<"  ";
        if(i!=1)
        for(j=1;j<=i;j++)
        cout<<j<<" ";
        cout<<endl;
        if(i==n)
        match=1;
        if(match==0)
        {   i++; space-=2;  gap+=2;}
        else
        {   i--; space+=2;  gap-=2;}
    }

    return 0;
}
