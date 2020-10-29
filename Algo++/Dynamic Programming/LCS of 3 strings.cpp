/*
LCS WITH 3 STRINGS
Given 3 strings ,the task is to find the longest common sub-sequence in all three given sequences.


Input Format:
First line contains first string . Second line contains second string. Third line contains the third string.

Constraints:
The length of all strings is |s|< 200

Output Format:
Output an integer denoting the length of longest common subsequence of above three strings.

Sample Input:
GHQWNV
SJNSDGH
CPGMAH
Sample Output:
2
Explanation:
"GH" is the longest common subsequence

Time Limit: 3 sec
*/
#include <bits/stdc++.h>
using namespace std;

int lcsOf3strings(string a,string b,string c){
    int dp[205][205][205];
    int m = a.size();
    int n = b.size();
    int p = c.size();

    for (int i=0; i<=m; i++)    {
        for (int j=0; j<=n; j++)        {
            for (int k=0; k<=p; k++)            {
                if (i == 0 || j == 0|| k == 0){
                    dp[i][j][k] = 0;
                }
                else if (a[i-1] == b[j-1] && a[i-1] == c[k-1]){
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                }
                else
                    dp[i][j][k] = max(max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);
            }
        }
    }

    return dp[m][n][p];
}



int main() {
    string a,b,c;
    cin >> a >> b >> c;

    cout << lcsOf3strings(a,b,c);

    return 0;
}

