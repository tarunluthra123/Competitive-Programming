/*
PATTERN MOUNTAIN
Take N (number of rows), print the following pattern (for N = 4).

                       1           1
                       1 2       2 1  
                       1 2 3   3 2 1
                       1 2 3 4 3 2 1   

Constraints:
0 < N < 10
Sample Input:
4
Sample Output:
1						1
1	2				2	1
1	2	3		3	2	1
1	2	3	4	3	2	1
Explanation:
Each number is separated from other by a tab.
*/

#include <iostream>
using namespace std;
int main() 
{
    int n,i,j,space;
    cin>>n;
    int check=0;
    for(i=0;i<n;i++)
    {   check=0;
        for(j=1;j>0;)
        {
            if(j<=i+1)
            {   cout<<j<<" ";   }
            else
            {   cout<<"  "; }
            if(j==n)
            check=1;
            if(check==0)
            j++;
            else
            j--;
        }
        cout<<endl;
    }
    return 0;
}

