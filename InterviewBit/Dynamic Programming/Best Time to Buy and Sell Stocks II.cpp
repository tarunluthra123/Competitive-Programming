//https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-ii/
int Solution::maxProfit(const vector<int> &A) {
    int n = A.size();
    int ans = 0;
    for(int i=1;i<n;i++){
        ans += max(0,A[i] - A[i-1]);
    }
    
    return ans;
}

