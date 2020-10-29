//https://www.hackerrank.com/challenges/candies/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dynamic-programming
// Complete the candies function below.
long candies(int n, vector<int> arr) {
    vector<int> dp(n,1);
    for(int i=1;i<n;i++){
        dp[i] = arr[i]>arr[i-1]? dp[i-1] + 1:dp[i];
    }

    for(int i=n-2;i>=0;i--){
        dp[i] = (arr[i]>arr[i+1] && dp[i]<=dp[i+1])? dp[i+1]+1:dp[i];
    }

    long ans=0;

    for(int i=0;i<n;i++){
        ans += dp[i];
        // cout<<dp[i]<<" ";
    }

    return ans;
}
