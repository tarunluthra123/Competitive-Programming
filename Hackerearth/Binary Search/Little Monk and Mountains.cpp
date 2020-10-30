/*
https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/little-monk-and-mountains/

Little Monk and Mountains
Little monk has travelled across the world but he has never seen a place like byteland. The mountains in the byteland have a unique order. 
Height of ith mountain is represented by an interval (l,R) i.e. the height of the mountain is in increasing order, . 
The heights of mountains are such that if i<j then ri < lj. Now the little monk wants to know xth smallest height in the byteland.

Note: x will be always in the given range of intervals.

Input Format:
First line contains two space separated integers, N (1 <=N<=10^5)  and Q  (1 <=Q<=10^5), number of mountains and number of queries.
Next N lines contains two separated integers each, l[i] and r[i] .( 1<=l[i],r[i] <=10^18) . ith line contains the starting height and the end height of the ith mountain.
Next Q lines contains one integer, x , each, denoting the queries.

Output Format:
For each query, print xth smallest height in the byteland.

SAMPLE INPUT 
3 3
1 10
11 20
21 30
5
15
25
SAMPLE OUTPUT 
5
15
25

*/
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define FOI(i, a, n) for( i = int(a); i <= int(n); i++)
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007

#define ff first
#define ss second

#define ll  long long int
#define pii pair<ll, ll>
#define vi  vector<ll>

int main() { 
    sync;
    
    ll n;
    cin >> n;
    ll q;
    cin >> q;
    vector < pii > v(n);
    for (ll i = 0; i < n; ++i) {
        cin >> v[i].ff >> v[i].ss ;
    }
    sort(v.begin(), v.end());

    vi cumSum(n,0);
    cumSum[0] = v[0].ss - v[0].ff + 1;
    for (ll i = 1; i < n; ++i) {
        cumSum[i] = cumSum[i-1] + v[i].ss - v[i].ff + 1;
    }

    while(q--) {
        ll k;
        cin >> k;

        ll index = lower_bound(cumSum.begin(),cumSum.end(),k) - cumSum.begin();  

        ll prevSum ;
        if(index <= 0)
            prevSum = 0;
        else 
            prevSum = cumSum[index-1];

        k -= prevSum;
        //cout << "k = " << k << "    index = " << index << endl;

        if(index < 0) {
            cout << k << '\n';
        }
        else {
            cout << k+v[index].ff-1 << '\n';
        }
        
    return 0;
}



