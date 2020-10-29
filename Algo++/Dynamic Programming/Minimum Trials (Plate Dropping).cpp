/*
MINIMUM TRIALS NEEDED (PLATE DROPPING)
Aakash has K identical plates and N floors. He needs to find the lowest floor at which the plate will break down aka critical floor. However, he doesn't like climbing stairs again and again. So he decided to take your help. Help him design a strategy that would tell him the minimum no of trials he need to perform for knowing the critical floor.

Assume that plate will only break at critical floor and floors higher than that.

_Hint :
_Recursion tells u what u intend to calculate._
Test case 3 is only for students who think that the test cases are easy.


Input Format:
The first line contains T, the number of test cases.
Next T line follows 2 space separated integers, first being the number of plates K, next being the number of floors N.

Constraints:
0 < T < 10

0 < K < 2

0 < N < 10

Output Format:
T lines of required answer

Sample Input:
1
2 3
Sample Output:
2
Explanation:
Aakash can start dropping plates from floor 1, 2 or 3.

Consider floor 1 :

If the plate breaks, critical floor is floor 1 else he moves to floor 2 and repeat the process. By this method minimum no of trials to know the critical floor are 3.

Consider he starts with 2nd floor.

Now if the plate breaks, the number of floors left to be checked is 1, floor 1. If it doesn't break, then floors to be tested is floor 3. In both the cases the number of trials are 2. So Akash will start from floor 2

Time Limit: 1 sec
*/
#include <bits/stdc++.h>
using namespace std;

int minTrialBottomUp(int k, int n) 
{ 
    int dp[k+1][n+1]; //dp[i][j] represents min of trials needed for i eggs and j floors
 
    // We need one trial for one floor and 0 trials for 0 floors 
    for (int i=1; i <= k; i++) { 
        dp[i][1] = 1; 
        dp[i][0] = 0; 
    } 
  
    // We always need j trials for one plate and j floors. 
    for (int j=1; j <= n; j++) {
        dp[1][j] = j; 
    }
  
    for (int i=2;i<=k;i++)  { 
        for (int j=2; j <= n; j++) { 
            dp[i][j] = INT_MAX; 
            for (int x=1; x <= j; x++) { 
                int res = 1 + max(dp[i-1][x-1], dp[i][j-x]); 
                dp[i][j] = min(dp[i][j],res) ;
            } 
        } 
    } 
  
    return dp[k][n]; 
} 


int main() {
    int testCases;
    cin >> testCases;
    while(testCases--){
        int k,n;
        cin >> k >> n;
        cout << minTrialBottomUp(k,n) << endl;
    }

    return 0;
}

