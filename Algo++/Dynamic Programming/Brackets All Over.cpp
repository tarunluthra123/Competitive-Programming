/*
BRACKETS ALL OVER
You are given a string containing only opening and closing brackets "(" and ")" of size m. You have to append 2 strings a and b in the order a+s+b and make them valid string of size n with the following properties,

At any index, number of opening brackets should be greater than closing brackets
No. of opening and closing brackets should be equal. You have to tell number of combinations of string a and b if its possible, otherwise print "0" Print the asnwer with modulo 10^9?+?7.

Input Format:
1st Line: n m 2nd Line: string s

Constraints:
1<= m <= n <= 10^5
n-m <= 1200

Output Format:
The number of combinations of a and b. Otherwise -1

Sample Input:
4 2
((
Sample Output:
1
Explanation:
Only 1 possible case a="" , b="))"

Time Limit: 1 sec
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007

int n, m;
ll dp[2222][2222][2];

int openingBrackets = 0, closeBrackets = 0;
int length = 0 ;

ll solve(int pos, int open, int close){
	if (pos == length) { 
        if(close > 0 && open == 0){
            return 1;
        }
        else {
            return 0;
        }
    }

	if (dp[pos][open][close] != -1){
        return dp[pos][open][close];
    }

	ll ans = 0;
	if (!close){
		if (open >= openingBrackets)
			ans = (ans + solve(pos + 1, open - openingBrackets + closeBrackets, 1)) % MOD;
	}

	ans = (ans + solve(pos + 1, open +1, close)) % MOD;

	if(open)
        ans = (ans + solve(pos + 1, open - 1, close)) % MOD;

    dp[pos][open][close] = ans;

	return ans;
}
int main(){
	cin >> n >> m;
	length = n - m + 1;
	string s;
    cin >> s;
	if (n & 1){
        //If n is odd, string can never be balanced
		cout << 0;
		return 0;
	}
	
	closeBrackets = 0;
	for(int i=0;i<m;i++){
		if (s[i] == '(') {
            //We need a closing bracket to balance this opening bracket
            closeBrackets++;
        }
		else {
            //Encountered a ) , reduce a the no of closing brackets required
            closeBrackets--;
        }
		if (closeBrackets < 0) {
            //More closing brackets than opening brackets , increase the no of opening brackets for string A
            openingBrackets++;
            closeBrackets = 0;
        }
	}

	memset(dp, -1, sizeof dp);

	cout << solve(0, 0, 0);

	return 0;
}

