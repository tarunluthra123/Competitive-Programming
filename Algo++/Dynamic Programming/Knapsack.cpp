/*
0-1 KNAPSACK
You are packing for a vacation on the sea side and you are going to carry only one bag with capacity S (1 <= S <= 1000). You also have N (1<= N <= 1000) items that you might want to take with you to the sea side. Unfortunately you can not fit all of them in the knapsack so you will have to choose. For each item you are given its size and its value. You want to maximize the total value of all the items you are going to bring. What is this maximum total value?


Input Format:
On the first line you are given N and S. Next line contains N space separated integer which is the size of things and next line contains the corresponding value of things.

Constraints:
1 <= S,N <= 1000

Output Format:
You should output a single integer on one like - the total maximum value from the best choice of items for your trip.

Sample Input:
5 4
1 2 3 2 2 
8 4 0 5 3
Sample Output:
13
Explanation:
Total capacity = 4. Pick size 1 with value 8 and size 2 with value 5.
*/
#include <iostream>
using namespace std;


//Recursive Approach
int knapsack(int n,int w,int *weights,int *prices){
    //Base case
    if(n == 0 || w == 0){
        return 0;
    }

    int include = 0 ;
    int exclude = 0 ;

    if(weights[n-1] <= w){
        //Include the current index element
        include = prices[n-1] + knapsack(n-1,w-weights[n-1],weights,prices) ; 
    }

    //Exclude the current element
    exclude = knapsack(n-1,w,weights,prices) ; 

    return max(include,exclude) ;
}

int knapsackBottomUp(int wts[],int prices[],int n,int w){
    int dp[1005][1005]={0};

    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0 || w==0){
                dp[i][j] = 0;
            }
            else {
                int include = 0 ,exclude = 0;
                if(wts[i-1]<=j){
                    include = prices[i-1] + dp[i-1][j-wts[i-1]] ; 
                }

                exclude = dp[i-1][j];

                dp[i][j] = max(include,exclude) ; 
            }
        }
    }

    return dp[n][w];
}



int main() {
    int n,w;
    cin >> n >> w;
    int weights[1005]={0};
    int prices[1005]={0};
    for(int i=0;i<n;i++){
        cin >> weights[i];
    }
    for(int i=0;i<n;i++){
        cin >> prices[i];
    }
    
   // cout << knapsack(n,w,weights,prices) <<endl; 
    cout << knapsackBottomUp(weights,prices,n,w) ;

    return 0;
}

