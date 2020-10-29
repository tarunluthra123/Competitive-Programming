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

//Bottom Up Appraoch using 1D DP

#include <bits/stdc++.h>
using namespace std;

#define ll long long int


//Using 1D DP
ll moneyExchangeBottomUp(ll amount,int *a,int n){
    ll dp[amount+1];

    //Initialise entire array as 0
    for(int i=1;i<=amount;i++){
        dp[i] = 0;
    }

    //1 way to make 0 amount ...use no coins
    dp[0] = 1;

    for(int i=0;i<n;i++){
        for(int j=a[i];j<=amount;j++){
            dp[j] = ( dp[j] + dp[j-a[i]] ) % 1000000007;
        }
    }

    return dp[amount];
}


int main()
{
    int testCases;
    cin>>testCases;
    while(testCases--) {
        int n;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++) {
            cin >> a[i];
        }
        ll amount;
        cin >> amount;

        cout << moneyExchangeBottomUp(amount,a,n) << endl;

    }

    return 0;
}
