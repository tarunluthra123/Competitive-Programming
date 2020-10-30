/*
https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/aaryan-subsequences-and-great-xor/

Aaryan, Subsequences And Great XOR

Aaryan went to school like any usual day, The teacher asked his crush the following question. Given an array of numbers, First she had to compute the XOR of all the subsequences that can be formed. Suppose each subsequence had their following XOR value that came out after computing -> {P[0], P[1], P[2], and so on upto P[2^n-1] subsequences in an array of n numbers}

Now, the resultant answer is computed by taking bitwise inclusive OR of all P[i]'s

Since, Aaryan wants to impress his crush, He wants to compute the answer for this problem but since he is not so good at it, he turned to you for help.

Input:
First line will consist of number N.
Then in the next line, there will be N numbers, ith number in the line is denoted by A[i]

Output:
Output the required value as answer.

Constraints:
1 <= N <= 10^6
0 <= A[i] <= 10^9

SAMPLE INPUT 
4
8 9 9 8
SAMPLE OUTPUT 
9

*/


#include <iostream>
using namespace std;

long filterInts(long a[],long n)
{
    long ans=0,i=0;
    while(n)
    {
        if(n&1)
        ans=ans^a[i];
        i++;
        n=n>>1;
    }
    return ans;
}

long findXOR(long a[],long size)
{
    long value,ans=0;
    long range=(1<<size)-1;
    for(long i=0;i<range;i++)
    {
        value=filterInts(a,i);
        ans=ans|value;
    }
    return ans;
}

int main() 
{
    long n,a[1000000],i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<findXOR(a,n);

    return 0;
}

