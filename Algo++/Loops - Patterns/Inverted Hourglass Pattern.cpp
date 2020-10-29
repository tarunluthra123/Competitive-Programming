/*
PATTERN INVERTEDHOURGLASS
Take N as input. For a value of N=5, we wish to draw the following pattern :

             5                   5 
             5 4               4 5 
             5 4 3           3 4 5 
             5 4 3 2       2 3 4 5 
             5 4 3 2 1   1 2 3 4 5 
             5 4 3 2 1 0 1 2 3 4 5 
             5 4 3 2 1   1 2 3 4 5 
             5 4 3 2       2 3 4 5 
             5 4 3           3 4 5 
             5 4               4 5 
             5                   5 

Input Format:
Take N as input.

Output Format:
Pattern should be printed with a space between every two values.

Sample Input:
5
Sample Output:
5                   5 
5 4               4 5 
5 4 3           3 4 5 
5 4 3 2       2 3 4 5 
5 4 3 2 1   1 2 3 4 5 
5 4 3 2 1 0 1 2 3 4 5 
5 4 3 2 1   1 2 3 4 5 
5 4 3 2       2 3 4 5 
5 4 3           3 4 5 
5 4               4 5 
5                   5 
*/
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i,j;
    int p,q;
    int r;
    int check;
    for(i=0;i<2*n+1;i++)
    {
        p=i<=n?i:2*n-i;
        q=n;
        check=0;
        for(j=0;j<=2*n;j++)
        {
            r=j<=n?j:2*n-j;
            if(r<=p)
            cout<<q<<" ";
            else
            cout<<"  ";
            if(q==0)
            check=1;
            if(check==0)
            q--;
            else
            q++;
        }
        cout<<endl;
    }
    return 0;
}
