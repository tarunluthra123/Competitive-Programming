/*
FOUND AT LAST
Take as input N, the size of array. Take N more inputs and store that in an array. Take as input M, a number. Write a recursive function which returns the last index at which M is found in the array and -1 if M is not found anywhere. Print the value returned.

Input Format:
There will be three lines of input:

N - the size of the array
N space separated integers that make up the array
M
Constraints:
1 < N < 1000
-10^9 < i,M < 10^9 , where i is any number within the array

Output Format
For each case, print the integer value of the last index that M is found at within the given array.
If it is not found, print '-1' (without the quotes).

Sample Input
7
86 -16 77 65 45 77 28
77
Sample Output
5
*/
#include <iostream>
using namespace std;
long long find(long long *a,long long i,long long n,long long m,long long ans)
{
    //Base case
    if(i==n)
        return ans;

    //test case
    if(a[i] == m)
        ans = i;

    //recursive case
    return find(a,i+1,n,m,ans);
}
int main() 
{
    long long n;
    cin>>n;
    long long *a = new long long[n];
    for(long long i=0;i<n;i++)
        cin>>a[i];

    long long m;
    cin>>m;
    cout<<find(a,0,n,m,-1);
    return 0;
}
