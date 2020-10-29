#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define FOI(i, a, n) for( i = int(a); i <= int(n); i++)
#define FOD(i, a, n) for( i = int(a); i >= int(n); i--)
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007

#define ll  long long int
#define pii pair<ll, ll>
#define vi  vector<ll>

#define ff first
#define ss second


//Returns sum of prime factors of K
ll primeSumOfK(ll k) { 
    // vector to store all the prime factors along with their number of occurrence in factorization of k 
    vector< pii > ans; 

    for(ll i = 2; k != 1; i++) { 
        if (k % i == 0) { 
            ll count = 0; 
            while (k % i == 0) { 
                k = k / i; 
                count++; 
            } 

            ans.pb(mp(i, count)); 
        } 
    } 
    
    ll i;
    ll primeSum = 0 ;
    FOI(i,0,ans.size()-1) {
        primeSum += (ans[i].ff*ans[i].ss) ;
    }

    return primeSum;
} 


ll nCr(ll n, ll r) {
    if (r == 0) {
        return 1;
    }

    if (r > n / 2) {
        return nCr(n, n - r); 
    }

    ll res = 1; 

    for (ll k = 1; k <= r; ++k) {
        res = (res * (n - k + 1) ) % MOD ;
        res /= k;
    }

    return res % MOD;
}

int main() {
    sync;
    ll primeModulus = 1000000;
    ll k;
    cin >> k;
    ll n;
    cin >> n;
    vi v(n);
    ll i ;
    FOI(i,0,n-1) {
        cin >> v[i];
    }

    ll primeSum = 0;
    FOI(i,0,n-1) {
        primeSum = (primeSum + primeSumOfK(v[i])) % primeModulus;
    }

    //cout << primeSum << endl;

    cout << nCr(primeSum+k-1,k-1);



    
    return 0;
}
