#include <bits/stdc++.h>
using namespace std;

int matrixChainMultiplication(vector<int> v)
{
    v.insert(v.begin(), 1);
    v.push_back(1);

    int n = v.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int k = 2; k < n; ++k)
    {
        for (int left = 0; left < n - k; ++left)
        {
            int right = left + k;
            for (int i = left + 1; i < right; ++i)
            {
                int currentVal = v[left] * v[i] * v[right] + dp[left][i] + dp[i][right];
                dp[left][right] = max(dp[left][right], currentVal);
            }
        }
    }

    return dp[0][n - 1];
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << matrixChainMultiplication(v) << "\n";

    return 0;
}
