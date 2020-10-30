/*
https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/danny-and-his-loneliness/

Rajan and Odd frequency number
Given an array of numbers of size (2*n+1).Raja is unable to find the number which is present odd number of times.It is guaranteed that only one such number exists.Can you help Raja in finding the number which is present odd number of times?

Input
First line contains value of n.
Second line contains (2*n+1) array elements. 
Output
Print the required number.
Constraints
1= n <= 10^9 
1= a[i] <= 10^9

SAMPLE INPUT 
2
1 2 3 2 1
SAMPLE OUTPUT 
3
Explanation
For first input only 3 is the number which is present odd number of times.
*/


#include <iostream>
using namespace std;
int main()
{
    long long n,i,ans=0;
    cin>>n;
    long long m;
    for(i=0;i<(2*n+1);i++)
    {
        cin>>m;
        ans=ans^m;
    }
    cout<<ans;
    return 0;
}
