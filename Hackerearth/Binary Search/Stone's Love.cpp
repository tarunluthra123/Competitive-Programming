/*
https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/stones-love/

Stone's Love
Senorita likes stones very much. As she is fond of collecting beautiful stones, everyday she finds some of the stones beautiful and collects it in her bottle.

You are given the number of stones, she collects each day for N numbers of days, starting from the very first day. Now you are given Q queries, in each query her friend shambhavi asks you the number of days she has taken to collect M number of stones. Please note that each query contains the different number of M.

Input:
First line contains N and Q, the number of days and number of queries. Second line contains N integers, in which ith integer denotes the number of stones she has collected on ith day.
Then next line contains Q space-separated integers, M, where ith M denotes the ith query, i.e., number of stones.

Output:
For each of the Q queries, you have to output the number of days she has taken to collect M number of stones in a new line.

Constraints:

1 <= N, Q <= 5*10^5
1 <= A[i] <= 10^5
1 <= M <= sum of all the elements in the array.

Problem Setter:

Akash Rakshit

SAMPLE INPUT 
5 4
1 2 3 4 5
3 8 10 14
SAMPLE OUTPUT 
2
4
4
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

ll binarySearch(vi &v,ll x) {
    ll s = 0;
    ll e = v.size()-1;
    ll ans = 1;
    while(s <= e) {
        ll mid = (s+e)/2;
        if(v[mid] == x) {
            return mid+1;
        }
        else if(v[mid] < x) {
            ans = mid+2;
            s = mid+1;
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
    ll q;
    cin >> q;
    vi v(n);
    cin >> v[0];
    for (int i = 1; i < n; ++i)  {
        ll x;
        cin >> x;
        v[i] = v[i-1] + x;
    }

    //for (int i = 0; i < n; ++i)        cout << v[i] << " ";    cout << endl;

    while(q--) {
        ll query;
        cin >> query;
        cout << binarySearch(v,query) << endl;
    }

    return 0;
}
