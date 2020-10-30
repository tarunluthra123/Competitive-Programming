/*
https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/the-enlightened-ones/description/

The Enlightened Ones
There are N temples in a straight line and K monks who want to spread their enlightening power to the entire road of temples. All the monks have an enlightenment value, which denotes the range of enlightenment which they can spread in both the directions. Since, they do not want to waste their efficiency on trivial things of the world, they want to keep their range minimum.

Also, when we say that the N temples are in a straight line, we mean that that all the temples lie on something like an X-axis in a graph.

Find the minimum enlightenment value such that all the temples can receive it.

Input Format:
The first line contains two integers, N and K - denoting the number of temples and number of monks. The next line contains N integers denoting the position of the temples in the straight line.

Output format:
Print the answer in a new line.

Constraints:
1 <= N <= 105
1 <= K < N 
1 <= Positioni <= 107

Update: 
The enlightenment value is an integer.

SAMPLE INPUT 
3 2
1 5 20
SAMPLE OUTPUT 
2
Explanation
The optimal answer is 2. A monk positioned at 3, can serve temples at 1 and 5. The other monk can be placed at 18, to serve temple at 20.
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

bool isValidConfig(vi &v,ll k,ll x) {
    ll n = v.size();
    unordered_map<int,bool> m;
    ll enlightened = 0;     //No of temples enlightened
    for (ll i = 0; i < n; ++i) {
        if(!m[v[i]]) {
            if(k<=0) {
                //No monks left 
                return false;
            }
            //If ith temple is unenlightened , place the monk x units front of him
            m[v[i]] = true;//Current temple is enlightened
            ll j ;
            for (j = i; j < n and v[j] <= v[i] + 2*x ; ++j) {
                m[v[j]] = true;
                enlightened++;
            }
            //cout << "j = " << j << endl;
            //i = j;
            k--;
        }
    }

    for (ll i = 0; i < n; ++i) {
        if(!m[v[i]]) {
            return false;
        }
    }
    return true;
}

ll enlighten(vi &v,ll k) {
    sort(v.begin(), v.end());
    ll s = 0;
    ll e = v[v.size()-1]/k;
    ll ans = INT_MAX;
    while(s<=e) {
        ll mid = (s+e)/2;
        //cout << "mid = " << mid << endl;
        if(isValidConfig(v,k,mid)) {
            ans = mid;
            e = mid-1;
            //cout << "e\n";
        }
        else {
            //cout << "s\n";
            s = mid+1;
        }
    }

    return ans;
}

int main() { 
    sync;
    ll n;
    cin >> n;
    ll k;
    cin >> k;
    vi v(n);
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
    }

    cout << enlighten(v,k);


    return 0;
}
