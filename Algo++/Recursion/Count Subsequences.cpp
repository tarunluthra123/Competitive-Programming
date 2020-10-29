/*
COUNT SUBSEQUENCES
Given a string, count the number of distinct subsequences of it ( including empty subsequence ). For the uninformed, A subsequence of a string is a new string which is formed from the original string by deleting some of the characters without disturbing the relative positions of the remaining characters. For example, "AGH" is a subsequence of "ABCDEFGH" while "AHG" is not.


Input Format:
First line of input contains an integer 't' denoting number of test cases. Each of next t lines contains a string s.

Constraints:
1<=t<=100
1<=length of s<=100000
s will contain upper letters only.

Output Format:
For each test case print ans%1000000007 where ans is the number of distinct subsequences.

Sample Input:
2
AAA
ABCDEFG
Sample Output:
4
128
Time Limit: 1 sec
*/
#include <bits/stdc++.h> 
using namespace std; 
#define lli long long int
#define MOD 1000000007

lli countSubsequences(string str) 
{ 
    map<char,lli> last ;
    for(char c='A'; c <= 'Z' ; c++){
        last[c] = -1;
    }
  
    lli n = str.length(); 
 
    lli dp[n+1];        //dp[i] represents no of distinct subsequences till index i
  
    // Empty substring has only one subsequence 
    dp[0] = 1; 
  
    for (lli i=1; i<=n; i++) { 
        //For each index we have two choices , whether to include the current char or not
        //Hence no of ways becomes twice of previous index
        dp[i] = (2 * dp[i-1]) % MOD;             
  
        //If current character has appeared before, then remove all subsequences ending with previous occurrence. 
        if (last[str[i-1]] != -1) {
            dp[i] = dp[i] - dp[last[str[i-1]]]; 
        }
  
        // Mark occurrence of current character 
        last[str[i-1]] = i-1; 
    } 
  
    return dp[n]; 
} 
 
int main() { 
    int testCases;
    cin >> testCases;
    while(testCases--){
        string s;
        cin >> s;
        cout << countSubsequences(s) << endl;
    }


    return 0;
} 
