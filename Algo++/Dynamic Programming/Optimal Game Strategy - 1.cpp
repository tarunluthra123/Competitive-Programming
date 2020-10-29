/*
OPTIMAL GAME STRATEGY-I
Piyush and Nimit are playing a coin game. They are given n coins with values x1, x2 …. xn where 'n' is always even. They take alternate terms. In each turn, a player picks either the first coin or the last coin from the row and removes it from the row. The value of coin is received by that player. Determine the maximum value that piyush can win if he moves first. Both the players play optimally.


Input Format:
First line contains the number of coins 'n'. Second line contains n space separated integers which is the value of ith coin.

Constraints:
N < 30

Output Format:
Print a single line with the maximum possible value.

Sample Input:
4
1 2 3 4
Sample Output:
6
Explanation:
Piyush will pick the coin 4. Then nimit can pick either 1 or 3. In both the cases piyush picks coin 2 and wins with a total of 6.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll coins[40];
ll dp[40][40];

ll optimalGame(ll i,ll j){
    if(i > j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    ll pickFirst = coins[i] + min( optimalGame(i+2,j) , optimalGame(i+1,j-1) ) ;
    ll pickLast = coins[j] + min( optimalGame(i,j-2) , optimalGame(i+1,j-1) ) ;

    dp[i][j] = max(pickFirst,pickLast);

    return dp[i][j];
}


int main() {
    ll n;
    cin >> n;   
    
    for(ll i=0;i<n;i++){
        cin >> coins[i];
    }

    memset(dp,-1,sizeof(dp)) ;
    cout << optimalGame(0,n-1);

    return 0;
}

