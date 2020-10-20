class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n - 1; i++)
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        for (int x : dp)
            cout << x << " ";
        cout << endl;
        int q1 = max(dp[n - 1], dp[n - 2]);
        int q2 = 0;

        if (n >= 3)
        {
            dp.resize(n);
            dp[1] = nums[1];
            dp[2] = max(nums[1], nums[2]);
            for (int i = 3; i < n; i++)
            {
                dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
            }
            for (int x : dp)
                cout << x << " ";
            q2 = dp[n - 1];
        }
        return max(q1, q2);
    }
};