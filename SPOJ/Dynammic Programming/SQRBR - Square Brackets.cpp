/*
SQRBR - Square Brackets
You are given:

a positive integer n,
an integer k, 1<=k<=n,
an increasing sequence of k integers 0 < s1 < s2 < ... < sk <= 2n.
What is the number of proper bracket expressions of length 2n with opening brackets appearing in positions s1, s2,...,sk?

Illustration
Several proper bracket expressions:

[[]][[[]][]] 
[[[][]]][][[]]
An improper bracket expression:

[[[][]]][]][[]]
There is exactly one proper expression of length 8 with opening brackets in positions 2, 5 and 7.

Task
Write a program which for each data set from a sequence of several data sets:

reads integers n, k and an increasing sequence of k integers from input,
computes the number of proper bracket expressions of length 2n with opening brackets appearing at positions s1,s2,...,sk,
writes the result to output.
Input
The first line of the input file contains one integer d, 1 <= d <= 10, which is the number of data sets. The data sets follow. Each data set occupies two lines of the input file. The first line contains two integers n and k separated by single space, 1 <= n <= 19, 1 <= k <= n. The second line contains an increasing sequence of k integers from the interval [1;2n] separated by single spaces.

Output
The i-th line of output should contain one integer - the number of proper bracket expressions of length 2n with opening brackets appearing at positions s1, s2,...,sk.

Example
Sample input:
5 
1 1 
1 
1 1 
2 
2 1 
1 
3 1 
2 
4 2 
5 7 

Sample output:
1 
0 
2 
3 
2
*/
#include <bits/stdc++.h>
using namespace std;

bool openIndex[50];
int dp[50][50];

//n in function is actually equal to 2*n of input
//pos indicated index
//open indicates the no of open brackets in current string

int n;

int squareBrackets(int pos = 0, int open = 0)
{
    if (open < 0)
    {
        return 0;
    }
    if (pos == n)
    {
        return (open == 0);
    }
    if (dp[pos][open] != -1)
    {
        return dp[pos][open];
    }
    int ans = 0;
    if (openIndex[pos])
    {
        return squareBrackets(pos + 1, open + 1);
    }
    ans = squareBrackets(pos + 1, open + 1) + squareBrackets(pos + 1, open - 1);

    dp[pos][open] = ans;

    return ans;
}

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        cin >> n;
        n = n << 1;

        int k;
        cin >> k;

        memset(openIndex, 0, sizeof(openIndex));

        for (int i = 0; i < k; i++)
        {
            int x;
            cin >> x;
            openIndex[x - 1] = 1;
        }

        memset(dp, -1, sizeof(dp));

        cout << squareBrackets() << endl;
        // cout << f(0, 0) << endl;
    }

    return 0;
}
