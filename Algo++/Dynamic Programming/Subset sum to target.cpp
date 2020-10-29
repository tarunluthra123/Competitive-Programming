/*
THE SUBSET SUM TO TARGET
Given a set of "n" non-negative integers, and a value "sum", determine if there is a subset of the given set with sum equal to given sum.


Input Format:
1st Line: n sum 2nd Line: a1 a2……an (Array Values)

Constraints:
1<= n <= 5000
1<= sum <= 10^7
1<= Ai <=10^5

Output Format:
Yes, if sum exist No, it sum does not exist

Sample Input:
5 10
1 2 3 4 5
Sample Output:
Yes
Time Limit: 1 sec
*/

#include <iostream>
using namespace std;

bool subsetSumTargetBottomUp(int *arr,int n,int sum){
    
    bool dp[n+1][sum+1];    //(i,j) signifies if sum = j is achievable at position i


    //0 sum is always reachable due to the presence of NULL subarray
    for(int i=0;i<=n;i++){
        dp[i][0] = true ;
    }

    //We cannot reach any target value if we include no elements
    for(int j=0;j<=sum;j++){
        dp[0][j] = false;
    }

    dp[0][0] = true;        //0 sum with NULL subarray

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j < arr[i-1]){
                //If current element is larger than the target sum itself , no choice but to leave it
                dp[i][j] = dp[i-1][j];
            }
            else {
                //Else consider both possibilies to include or to exclude it
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]] ;
            }
        }
    }

    /*
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            cout << dp[i][j] << " "; 
        }
        cout << endl;
    }
    */



    return dp[n][sum] ;   
}


int **memo;        //Pointer to pointer allocated memory dynamically in main

int subsetSumTargetTopDown(int *a,int n,int sum){
    if(sum == 0){
        return 1 ;
    }
    if(n == 0){
        return 0 ;
    }

    if(memo[n][sum] != -1){
        return memo[n][sum] ;
    }

    int ans = 0 ;
    if(a[n-1] > sum){
        ans = subsetSumTargetTopDown(a,n-1,sum);
    }
    else {
        ans = subsetSumTargetTopDown(a,n-1,sum) | subsetSumTargetTopDown(a,n-1, sum - a[n-1]) ;
    }

    
    memo[n][sum] = ans ;

    return ans ; 
}


int main() {
    int n;
    cin >> n;
    int sum ;
    cin >> sum ;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    memo = new int*[n+1];
    for(int i=0;i<=n;i++){
        memo[i] = new int[sum+1];
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            memo[i][j] = -1 ;
        }
    }

   // bool ans = subsetSumTargetBottomUp(a,n,sum);
    bool ans = subsetSumTargetTopDown(a,n,sum) ;
    if(ans){
        cout << "Yes";
    }
    else {
        cout << "No";
    }


    return 0;
}

