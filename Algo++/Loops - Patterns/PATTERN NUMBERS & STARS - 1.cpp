//https://hack.codingblocks.com/contests/c/537/625
/*
Take as input N, a number. Print the pattern as given in output section for corresponding input.


Input Format:
Enter value of N

Output Format:
All numbers and stars are Space separated

Sample Input:
5
Sample Output:
1 2 3 4 5
1 2 3 4 * 
1 2 3 * * *
1 2 * * * * *
1 * * * * * * *
Explanation:
Catch the pattern for the corresponding input and print them accordingly.
*/
#include <iostream>
using namespace std;
int main() 
{
    int n,i,j,k;
    cin>>n;
    int stars=-1;
    for(i=1;i<=n;i++)
    {   
        k=n-i+1;
        for(j=1;j<=k;j++)
        {
            cout<<j<<" ";
        }
        for(j=0;j<stars;j++)
        cout<<"* ";
        stars++;    stars++;
        cout<<endl;
    }




    return 0;
}
