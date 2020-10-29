/*
You are given an array of numbers and a target number(T) , print all unique combinations in the array whose sum equals the target number T. Note that each number in the array may only be used once in the combination.
Note:

All numbers (including target) will be positive integers
Elements in the combination must be in non-descending order
There should be no duplicate combinations

Input Format:
The first line will contain N indicating the number of elements in the array.
The second line will contain space separated N integers , A[i]. 
The third line will contain the target number T.

Constraints:
N <= 15
1<= A[I] <= 100

Output Format:
Print all unique combinations of the numbers satisfying the above constraints in a separate line in lexicographic manner.

Sample Input:
7
10 1 2 7 6 1 5
8
Sample Output:
1 1 6 
1 2 5 
1 7 
2 6 

*/

#include <iostream>
#include <algorithm>
using namespace std;
int ans[1000][20] = {0};
int c = 0;
int size[1000] = {0};
bool checkIfPresent(int b[],int n)
{
    for(int i=0;i<c;i++)
    {
        if(n == size[i])
        {   
            int j;
            for(j=0;j<n;j++)
            {
                if(ans[i][j] == b[j])
                {}
                else
                    break;
            }
            if(j==n)    
                return true;    //already present
        }
    }
    return false;   //not present
}
void subsequences(int a[],int b[],int n,int i,int j,int t)
{
    //base case
    if(i==n)
    {
        int sum = 0;
        for(int k=0;k<j;k++)
        {
            sum+=b[k];
        }
        if(sum == t)
        {
            bool check = checkIfPresent(b,j);
            if(check)
                return ;

            //Copy b to ans
            for(int k=0;k<j;k++)
            {
                ans[c][k] = b[k];
            }
            size[c++] = j;
        }
        return ;
    }

    //recursive case
    b[j] = a[i];
    subsequences(a,b,n,i+1,j+1,t);

    subsequences(a,b,n,i+1,j,t);
}
int main() 
{
    int n ;
    cin>>n;
    int a[20];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int t;
    cin>>t;
    sort(a,a+n);

    int b[20];
    subsequences(a,b,n,0,0,t);

    for(int i=0;i<c;i++)
    {
        for(int j=0;j<size[i];j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}


