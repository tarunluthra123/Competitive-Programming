/*
UNIQUE NUMBER - III
We are given an array containg n numbers. All the numbers are present thrice except for one number which is only present once. Find the unique number. Only use - bitwise operators, and no extra space.


Input Format:
First line contains the number n. Second line contains n space separated number.

Constraints:
N < 10^5
Output Format:
Output a single line containing the unique number

Sample Input:
7
1 1 1 2 2 2 3
Sample Output:
3

*/
#include <iostream>
using namespace std;
int main() 
{   
    int a[100000],n,i,ans=0,b[sizeof(int)]={0};
    int j;
    cin>>n;
    for(i=0;i<n;i++)
    {   cin>>a[i];
        j=0;    
        int temp=a[i];
        while(temp)
        {   
            b[j]+=(temp&1);
            j++;
            temp=temp>>1;
        }
    }
    int q=0;
    ans=0;
    for(i=0;i<sizeof(int);i++)
    {
        q=b[i]%3;
        ans=ans+q*(1<<i);        
    }
    cout<<ans;
    return 0;
}

