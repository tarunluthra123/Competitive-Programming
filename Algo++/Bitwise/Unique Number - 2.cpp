/*
UNIQUE NUMBERS - II
We are given an array containg n numbers. All the numbers are present twice except for two numbers which are present only once. Find the unique numbers in linear time without using any extra space. ( Hint - Use Bitwise )


Input Format:
First line contains the number n. Second line contains n space separated number.

Constraints:
n < 10^5
Output Format:
Output a single line containing the unique numbers separated by space

Sample Input:
4
3 1 2 1
Sample Output:
2 3
*/

#include<iostream>
using namespace std;
int main() 
{
    int n,i,ans=0;
    cin>>n;
    int m=0;
    int a[100000];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        ans=ans^a[i];
    }
    int temp=ans;
    i=0;
    while(temp)
    {
        if(temp&1)
        break;
        i++;
        temp=temp>>1;
    }
    int mask=1<<i;
    for(i=0;i<n;i++)
    {
        if(mask&a[i])
        m=m^a[i];
    }
    int q=m^ans;
    cout<<min(m,q)<<" "<<max(m,q);
	return 0;
}
