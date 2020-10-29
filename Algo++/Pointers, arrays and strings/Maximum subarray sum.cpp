/*
MAXIMUM SUBARRAY SUM
You are given a one dimensional array that may contain both positive and negative integers, find the sum of contiguous subarray of numbers which has the largest sum. For example, if the given array is {-2, -5, 6, -2, -3, 1, 5, -6}, then the maximum subarray sum is 7.


Input Format:
The first line consists of number of test cases T. Each test case consists of N followed by N integers.

Constraints:
1 <= N <= 100000
1 <= t <= 20
?0 <= A[i] <= 100000000
Output Format:
The maximum subarray sum

Sample Input:
2
4
1 2 3 4
3
-10 5 10
Sample Output:
10
15
*/

#include <iostream>
using namespace std;
int main() 
{
    int test;
    long long a[100000];
    long n;
    cin>>test;
    while(test--)
    {
        cin>>n;        
        for(long i=0;i<n;i++)
        {   cin>>a[i];  }
        int sum=0,maxsum=0;
        for(long i=0;i<n;i++)
        {
            sum+=a[i];
            if(maxsum<sum)
            maxsum=sum;
            if(sum<0)
            {   sum=0;  }
        }
        cout<<maxsum<<endl;
    }


    return 0;
}

