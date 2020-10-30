/*
https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/sum-of-numbers-9/

Sum of Numbers

Given an array of N elements, check if it is possible to obtain a sum of S, by choosing some (or none) elements of the array and adding them.

Input:
First line of the input contains number of test cases T. Each test case has three lines.
First line has N, the number of elements in array.
Second line contains N space separated integers denoting the elements of the array.
Third line contains a single integer denoting S.

Output:
For each test case, print "YES" if S can be obtained by choosing some(or none) elements of the array and adding them. Otherwise Print "NO".

Note that 0 can always be obtained by choosing none.

Constraints
1 <=T <= 10
1 <= N <= 15
-10^6 <= A[i] <= 10^6 for 0 <= i < N

SAMPLE INPUT
3
5
3 2 0 7 -1
8
3
-1 3 3
4
3
4 -5 1
5


SAMPLE OUTPUT
YES
NO
YES

*/


//https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/sum-of-numbers-9/
#include <iostream>
using namespace std;

long filterInts(long a[],long n)
{
    long s=0,i=0;
    while(n)
    {
        if(n&1)
        s=s+a[i];
        i++;
        n=n>>1;
    }
    return s;
}

bool findSum(long a[],long size,long s)
{
    long value;
    long range=(1<<size)-1;
    for(long i=0;i<range;i++)
    {
        value=filterInts(a,i);
        if(value==s)
        return true;
    }
    return false;
}

int main()
{
    long test,n;
    long a[100]={0},s;
    cin>>test;
    long i;
    while(test--)
    {
        cin>>n;
        for(i=0;i<n;i++)
            cin>>a[i];
        cin>>s;
        n++;        //size of array increased by one otherwise testcase of 15 array elements do not pass
        if(findSum(a,n,s))
        cout<<"YES";
        else
        cout<<"NO";
        cout<<endl;
    }
    return 0;
}
