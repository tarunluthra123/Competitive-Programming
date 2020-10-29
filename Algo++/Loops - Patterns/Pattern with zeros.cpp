/*
PATTERN WITH ZEROS
Take N (number of rows), print the following pattern (for N = 5)
1
2 2
3 0 3
4 0 0 4
5 0 0 0 5


Constraints:
0 < N < 100
Sample Input:
5
Sample Output:
1  
2	2  
3	0	3    
4	0	0	4  
5	0	0	0	5
Explanation:
Each number is separated from other by a tab.If row number is n (>1), total character is n. First and last character is n and rest are 0.

*/

#include <iostream>
using namespace std;
int main() 
{
    int n,i,j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {   
            if(j==0||j==i)
            cout<<i+1;
            else
            cout<<"0";
            cout<<"\t";
        }
        cout<<endl;

    }


    return 0;
}

