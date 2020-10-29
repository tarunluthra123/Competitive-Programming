//Take N as input. For a value of N=5, we wish to draw the following pattern :
/*
                          5 4 3 2 1 0 1 2 3 4 5
                            4 3 2 1 0 1 2 3 4 
                              3 2 1 0 1 2 3 
                                2 1 0 1 2 
                                  1 0 1 
                                    0 
                                  1 0 1 
                                2 1 0 1 2 
                              3 2 1 0 1 2 3 
                            4 3 2 1 0 1 2 3 4 
                          5 4 3 2 1 0 1 2 3 4 5
*/
#include <iostream>
using namespace std;
int main() 
{
    int n,i,j,k;
    int check;
    int match=0;
    cin>>n;
    int x=2*n+1;
    for(i=0;i>=0;)
    {
        check=0;
        for(j=n;j<=n;)
        {   
            if(i+j<=n)
            cout<<j<<" ";
            else
            cout<<"  ";
            if(j==0)
            check=1;
            if(check==0)
            j--;
            else
            j++;
        }
        cout<<endl;
        if(i==n)
        match=1;
        if(match==0)
        i++;
        else
        i--;
    }


    return 0;
}
