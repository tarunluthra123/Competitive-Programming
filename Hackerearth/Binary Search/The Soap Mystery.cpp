/*
https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/the-soap-mystery/

The Soap Mystery
Cool boy goes to buy soap from a shop.The shop contains N soaps. The prices of soap are given in the form of an array A. The price of ith soap is A[i]. Now cool boy has q queries, in each query he wants to know the number of soaps that have price less than the given amount M.

Input:

First line contains integer N total number of soaps available in the shop.

Second line contains N space separated integers.

Third line contains Q number of queries.

Each of the next Q lines contain integer M.

Output:

For each query output number of soaps having price less than M for that query.

Constraints:

1 = N = 10^5

1 = A[i] = 10^9

1 = Q = 10^5

1 = M = 10^5

SAMPLE INPUT 
5
1 4 10 5 6
4
2
3
5
11
SAMPLE OUTPUT 
1
1
2
5

*/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define FOI(i, a, n) for( i = int(a); i <= int(n); i++)
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007

#define ll  long long int
#define pii pair<ll, ll>
#define vi  vector<ll>

ll findInArray(vi &v,ll k) {
    ll s = 0;
    ll e = v.size()-1;
    ll ans = -1;
    

    while(s<=e) {
        ll mid = (s+e)/2;
        if(v[mid] < k) {
            
            s = mid+1;
         
            ans = mid;
        }
        else {
            e = mid-1;
        }
    }
    return ans;
}

int main() { 
    sync;
    ll n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int testCases;
    cin >> testCases;
    while (testCases--) {
        ll x;
        cin >> x;

        cout << findInArray(v,x)+1 << endl;
    }

    return 0;
}
