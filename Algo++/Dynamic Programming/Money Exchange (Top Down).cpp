/*
MONEY CHANGE
Given a big amount N and the array of denominations S. Assuming infinite supply of each of S = {S1,S2….Sm} denominations, find the number of ways to make change for N cents.


Input Format:
First line contains an integer T denoting the total number of test cases.
For every test case, there are three lines. 
First line will contain an integer 'M' denoting the size of array. 
The second line contains M space-separated integers A1, A2, …, Am denoting the elements of the array. 
The third line contains an integer 'N' denoting the cents. 

Constraints:
1 <= T <= 10
1 <= n <= 500
1 <= S[i] <= 1000
1 <= N <= 1000000

Output Format:
Print number of possible ways to make change for N cents in a new line. Since answers can be large, print answer % (1000000000 + 7).

Sample Input:
2
3
1 2 3
4
4
2 5 3 6
10
Sample Output:
4
5
Explanation:
For N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.

Time Limit: 2 sec
*/


//Top Down Approach ... fails one testcase due to large recursive calls

#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
using namespace std;

#define SIZE 530000
//           1000000
ll dp[502][SIZE];

ll money(int *s,int n,ll amount,int i){
    if(amount == 0){
        //If amount is 0 , there is 1 way to make this amount by using no coins
        return 1;
    }
    if(i == n){
        //No more coins left , no way to make the amound
        return 0;
    }
    if(amount < 0){
        //Amount is -ve , no way to make this amount using given coins
        return 0;
    }

    if(amount < SIZE && dp[i][amount]!=-1){
        return dp[i][amount];
    }

    ll ans = 0 ;
    ll includeCurrentCoin = money(s,n,amount-s[i],i);
    ll excludeCurrentCoin = money(s,n,amount,i+1) ;

    ans = includeCurrentCoin + excludeCurrentCoin ; 

    ans = ans % MOD;

    if(amount < SIZE)
        dp[i][amount] = ans ;

    return ans;
}

int main() {
    int testCases;
    cin >> testCases;
    while(testCases--){
        memset(dp,-1,sizeof(dp));
        int n;
        cin >> n;
        int s[n];
        for(int i=0;i<n;i++){
            cin >> s[i];
        }
        ll amount ;
        cin >> amount ;
        cout << money (s,n,amount,0) << endl;
    }

    return 0;
}

