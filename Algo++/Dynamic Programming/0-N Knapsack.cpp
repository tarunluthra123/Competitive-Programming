/*
0-N KNAPSACK
You've heard of 0-1 knapsack. Below is the problem statement for the same.

Given weights and values of n items, put these items in a knapsack of capacity cap to get the maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an integer cap which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to cap. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
There is a little twist for 0-N knapsack. You can pick an element more than once. Now you have to find maximum value multi subset of val[] such that sum of the weights of this subset is smaller than or equal to cap.

Note: Maximum value subset means the sunset with maximum sum of all the values in subset.

Input Format:
The first line contains two integers, representing n(size of val[]) and cap respectively. The subsequent line contains n integers representing the wt[] array. The next line, again, contains n integers representing the val[] array.

Constraints:
1 <= n,cap <= 1000 1 <= wt[i] <= cap 1 <= val[i] <= 100000

Output Format
Print a single integer, the answer to the problem.

Sample Input
5 11
3 2 4 5 1
4 3 5 6 1
Sample Output
16
*/
#include <iostream>
using namespace std;
#define lli long long int

//Recursive Approach
lli knapsack(lli n,lli w,lli *weights,lli *prices){
    //Base case
    if(n == 0 || w == 0){
        return 0;
    }

    lli include = 0 ;
    lli exclude = 0 ;

    if(weights[n-1] <= w){
        //Include the current index element
        include = prices[n-1] + knapsack(n-1,w-weights[n-1],weights,prices) ; 
    }

    //Exclude the current element
    exclude = knapsack(n-1,w,weights,prices) ; 

    return max(include,exclude) ;
}

lli knapsackBottomUp(lli wts[],lli prices[],lli n,lli w){
    lli dp[1005][1005]={0};

    for(lli i=0;i<=n;i++){
        for(lli j=0;j<=w;j++){
            if(i==0 || w==0){
                dp[i][j] = 0;
            }
            else {
                lli include = 0 ,exclude = 0;
                if(wts[i-1]<=j){
                    include = prices[i-1] + dp[i][j-wts[i-1]] ; 
                }

                exclude = dp[i-1][j];

                dp[i][j] = max(include,exclude) ; 
            }
        }
    }

    return dp[n][w];
}



int main() {
    lli n,w;
    cin >> n >> w;
    lli weights[1005]={0};
    lli prices[1005]={0};
    for(lli i=0;i<n;i++){
        cin >> weights[i];
    }
    for(lli i=0;i<n;i++){
        cin >> prices[i];
    }
    
   // cout << knapsack(n,w,weights,prices) <<endl; 
    cout << knapsackBottomUp(weights,prices,n,w) ;

    return 0;
}

