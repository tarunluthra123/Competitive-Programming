/*
KNAPSACK - The Knapsack Problem
The famous knapsack problem. You are packing for a vacation on the sea side and you are going to carry only one bag with capacity S (1 <= S <= 2000). You also have N (1<= N <= 2000) items that you might want to take with you to the sea side. Unfortunately you can not fit all of them in the knapsack so you will have to choose. For each item you are given its size and its value. You want to maximize the total value of all the items you are going to bring. What is this maximum total value?

Input
On the first line you are given S and N. N lines follow with two integers on each line describing one of your items. The first number is the size of the item and the next is the value of the item.

Output
You should output a single integer on one like - the total maximum value from the best choice of items for your trip.

Example
Input:
4 5
1 8
2 4
3 0
2 5
2 3


Output:
13The famous knapsack problem. You are packing for a vacation on the sea side and you are going to carry only one bag with capacity S (1 <= S <= 2000). You also have N (1<= N <= 2000) items that you might want to take with you to the sea side. Unfortunately you can not fit all of them in the knapsack so you will have to choose. For each item you are given its size and its value. You want to maximize the total value of all the items you are going to bring. What is this maximum total value?

Input
On the first line you are given S and N. N lines follow with two integers on each line describing one of your items. The first number is the size of the item and the next is the value of the item.

Output
You should output a single integer on one like - the total maximum value from the best choice of items for your trip.

Example
Input:
4 5
1 8
2 4
3 0
2 5
2 3


Output:
13
*/
#include <bits/stdc++.h>
using namespace std;

#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int

ll dp[2005][2005];

//Recursive Approach
ll knapsack(ll n, ll w, ll *weights, ll *prices)
{
    //Base case
    if (n == 0 || w == 0)
    {
        return 0;
    }

    if (dp[n][w] != -1)
    {
        return dp[n][w];
    }

    ll include = 0;
    ll exclude = 0;

    if (weights[n - 1] <= w)
    {
        //Include the current index element
        include = prices[n - 1] + knapsack(n - 1, w - weights[n - 1], weights, prices);
    }

    //Exclude the current element
    exclude = knapsack(n - 1, w, weights, prices);

    dp[n][w] = max(include, exclude);

    return dp[n][w];
}

int main()
{
	sync;
    ll n, w;
    // cin >> n >> w;
    cin >> w >> n;
    ll weights[2005] = {0};
    ll prices[2005] = {0};
    for (ll i = 0; i < n; i++)
    {
        cin >> weights[i] >> prices[i];
    }
    // for (ll i = 0; i < n; i++)
    // {
    //     cin >> prices[i];
    // }

    memset(dp, -1, sizeof(dp));

    cout << knapsack(n, w, weights, prices);

    return 0;
}

