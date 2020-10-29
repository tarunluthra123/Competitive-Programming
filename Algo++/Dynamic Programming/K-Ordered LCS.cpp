/*
K-ORDERED LCS
Any programmer worth his salt would be familiar with the famous Longest Common Subsequence problem. Mancunian was asked to solve the same by an incompetent programmer. As expected, he solved it in a flash. To complicate matters, a twist was introduced in the problem.

In addition to the two sequences, an additional parameter k was introduced. A k-ordered LCS is defined to be the LCS of two sequences if you are allowed to change atmost k elements in the first sequence to any value you wish to. Can you help Mancunian solve this version of the classical problem?


Input Format:
The first line contains three integers N, M and k, denoting the lengths of the first and second sequences and the value of the provided parameter respectively. The second line contains N integers denoting the elements of the first sequence. The third line contains M integers denoting the elements of the second sequence.

Constraints:
1 <= N, M <= 2000 
1 <= k <= 5
1 <= element in any sequence <= 109

Output Format:
Print the answer in a new line.

Sample Input:
5 5 1
1 2 3 4 5
5 3 1 4 2
Sample Output:
3
Time Limit: 2 sec
*/
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

lli dp[2005][2005][6];

lli kOrderedLCS(lli *a,lli *b,lli i,lli j,lli n,lli m,lli k){
    
    if(i>=n || j>=m){
        return 0;
    }

    if(dp[i][j][k]!=-1){
        return dp[i][j][k];
    }

    lli res = 0;

    if(a[i] == b[j]){
        res = 1 + kOrderedLCS(a,b,i+1,j+1,n,m,k) ;
    }
    else {
        if(k>0){
            res = 1 + kOrderedLCS(a,b,i+1,j+1,n,m,k-1) ;
        }
        res = max(res, kOrderedLCS(a,b,i+1,j,n,m,k)) ;
        res = max(res, kOrderedLCS(a,b,i,j+1,n,m,k)) ;
    }

    return dp[i][j][k] = res ;
}


int main(){
    lli n,m,k;
    cin >> n >> m >> k;
    lli a[n];
    lli b[m];
    for(lli i=0;i<n;i++){
        cin >> a[i];
    }
    for(lli j=0;j<m;j++){
        cin >> b[j];
    }

    //Initialise DP Array as -1
    for(lli i=0;i<=n;i++){
        for(lli j=0;j<=m;j++){
            for(lli l=0;l<=k;l++){
                dp[i][j][l] = -1;
            }
        }
    }


    cout << kOrderedLCS(a,b,0,0,n,m,k) ; 

    return 0;
}
