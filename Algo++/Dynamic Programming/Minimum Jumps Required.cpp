/*
MINIMUM JUMPS REQUIRED
You are provided an array of integers where each element represents the max number of steps you can take to move ahead. You need to check that how many minimum steps required to reach at the end of the array.


Input Format:
First line contains integer t which is number of test case. For each test case, it contains an integers n which the size of array A[]. Next line contains n space separated integers.

Constraints:
1<=t<=50
1<=n<=1000
0<=A[i]<=100

Output Format:
Print the minimum number of jumps.

Sample Input:
1
11
1 3 5 8 9 2 6 7 6 8 9
Sample Output:
3
Explanation:
1-> 3 (you can pick 5 or 8 or 9 , pick either 8 or 9) -> 8 -> 9
*/
#include <bits/stdc++.h>
using namespace std;

#define MAX 2000

int dp[1005];

int minJumps(int *a,int n,int i){
    if(i >= n-1) {
        return 0;
    }
    if(dp[i] < MAX){
        return dp[i];
    }

    int x = a[i] ; 

    if(x == 0){
        return MAX ;
    }

    int ans = MAX ; 
    for(int jump = 1;jump <= x; jump++){
        ans = min(ans,1 + minJumps(a,n,i+jump)) ;
    }

    dp[i] = ans;

    return ans;
}

//O(n) solution ... better
int jump(vector<int> &nums)
{
    int steps = 0;
    int currentMax = 0;
    int nextMax = nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > currentMax)
        {
            steps++;
            currentMax = nextMax;
        }
        nextMax = max(nextMax, i + nums[i]);
    }
    return steps;
}



int main() {
    int testCases;
    cin >> testCases;
    while(testCases--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        for(int i=0;i<1005;i++){
            dp[i] = MAX ;
        }

        cout << minJumps(a,n,0) ; 

        cout << endl;

        /*
        cout << "DP Array - ";
        for(int i=0;i<=n;i++){
            cout << dp[i] << " ";
        } 
        cout << endl;
        */
    }
       
    
    return 0;
}

