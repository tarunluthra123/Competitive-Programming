/*
You are provided n numbers (both +ve and -ve). Numbers are arranged in a circular form. You need to find the maximum sum of consecutive number.


Input Format:
First line contains integer t which is number of test case. For each test case, it contains an integer n which is the size of numbers and next line contains n space separated integers.

Constraints:
1<=t<=100
1<=n<=1000

Output Format:
Print the maximum sum.

Sample Input:
1
7
8 -8 9 -9 10 -11 12
Sample Output:
22
Explanation:
Maximum Sum = 22 (12 + 8 - 8 + 9 - 9 + 10)
*/
#include <bits/stdc++.h>
using namespace std;

int kadane(int *a, int n)
{
    int cs = 0;
    int ms = 0;
    for (int i = 0; i < n; i++)
    {
        cs += a[i];
        if (cs < 0)
            cs = 0;
        ms = max(ms, cs);
    }
    return ms;
}

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        int n;
        cin >> n;
        int a[1005];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int maxSum = kadane(a, n);

        int totalSum = 0;

        //Invert the array
        for (int i = 0; i < n; i++)
        {
            totalSum += a[i];
            a[i] = -a[i];
        }

        int invertedSum = kadane(a, n);

        int ans = max(maxSum, totalSum + invertedSum);

        cout << ans << endl;
    }

    return 0;
}

