/*
PRINT LCS
A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements. For example, the sequence {A,B,D} is a subsequence of {A,B,C,D,E,F}, obtained after removal of elements C, E and F.

Given two strings A and B of size n and m respectively, you have to print the Longest Common Subsequence(LCS) of strings A and B, where LCS is the longest sequence present in both A and B.

Note: It is gauranteed that there is only one unique longest common subsequence


Input Format:
Two strings A and B.

Constraints:
1 <= n,m <= 10^3

Output Format:
Output the LCS of A and B.

Sample Input:
abc
acd
Sample Output:
ac
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
string dp[MAX][MAX];

string printLCS(string a,string b,int i,int j){

    string ans = "";
    if(a.size() == i || b.size() == j){
        return ans ;
    }

    if(dp[i][j]!=""){
        return dp[i][j];
    }


    if(a[i] == b[j]){
        ans += a[i];
        string temp = printLCS(a,b,i+1,j+1) ;
        ans += temp ;
    }
    else {
        string temp1 = printLCS(a,b,i+1,j) ;
        string temp2 = printLCS(a,b,i,j+1) ;
        if(temp1.size() >= temp2.size())  {
            ans += temp1;
        }
        else {
            ans += temp2;
        }
    }
    dp[i][j] = ans ;

    return ans ;
}

int main() {
    string a,b;
    cin >> a >> b;
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            dp[i][j] = "";
        }
    }

    cout << printLCS(a,b,0,0);


    return 0;
}
