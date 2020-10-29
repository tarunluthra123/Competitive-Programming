/*
TILLING PROBLEM - II
Given a floor of size n x m. Find the number of ways to tile the floor with tiles of size 1 x m .


Input Format:
First line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
The first line of each test case contains two integers N and M.

Constraints:
1 <= T<= 1000
1 <= N,M <= 100000

Output Format:
Print answer for every test case in a new line modulo 10^9+7.

Sample Input:
2
2 3
4 4
Sample Output:
1
2
*/
#include <bits/stdc++.h>
#define MOD 1000000007
#define lli long long int
using namespace std;

lli dp[100005] ;

lli f(lli n,lli m)  {
    if(n<m)
        return 1;

    if(n==m)
        return 2;

    if(dp[n]!=-1){
        return dp[n];
    }

    //Recursive case
    lli ans =  f(n-1,m) + f(n-m,m);

    dp[n] = ans % MOD ;

    return ans%MOD ;
}


int main() 
{
    int t;
    cin>>t;

    while(t--)    {

        memset(dp,-1,sizeof(dp)) ;

        lli n,m;
        cin >> n >> m;

        cout<< f(n,m) % MOD <<endl;
    }


    return 0;
}
