//https://www.hackerrank.com/challenges/max-array-sum/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=dynamic-programming
int maxSubsetSum(vector<int> arr) {
    int n = arr.size();
    vector<int> dp(n);
    dp[0]=max(0,arr[0]);
    if(n==1)
        return dp[0];
    dp[1]=max(max(arr[0],arr[1]),0);
    for(int i=2;i<n;i++){
        dp[i]=max(0,max(dp[i-1],arr[i]+dp[i-2]));
    }
    return dp[n-1];
}
