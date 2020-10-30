/*
https://www.hackerearth.com/problem/algorithm/number-of-divisors-3-4f073391/


Little Shino and Number of Divisors

You are given an integer array A of size x denoting the prime powers of an integer N.A[i]  denotes the power of ith prime in the prime factorization of N.
To make it more clear,A[1]  will denote the power of 2 in the prime factorization of N,A[2]  will denote the power of 3 in the prime factorization of N 
and so on.

Consider a number P equals to the product of all the divisors of N. You have to find the number of divisors of P. Output it modulo 10^9+7.
*/
#include <bits/stdc++.h>
using namespace std;

#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007

#define ll  long long int
#define vi  vector<ll>

ll x, y;
void extendedEuclidAlgo(ll a,ll b) {
    if(b == 0) {
        x = 1;
        y = 0;
        return ;
    }
    extendedEuclidAlgo(b, a%b);
    ll cX = y;
    ll cY = x - (a/b)*y;
    x = cX;
    y = cY;
}


ll modInverse (ll A, ll M)  {
    extendedEuclidAlgo(A, M);
    return (x % M + M) % M; //x may be negative
}

int main()  {
    // No of divisors for a no N = product of (primePower[i]+1)

    ll n;
    cin >> n;
    vi v (n);

    ll s = 1;       //s is the product of all (powersOfPrime + 1)

    for (int i = 0; i < n; i++)    {
        cin >> v[i];
        v[i]++;
        v[i] = v[i] % MOD;
        s = (s * (v[i]) ) % MOD;
    }

    ll ans = 1;

    for (int i = 0; i < n; i++)    {

        // t = (s/v[i])%MOD
        ll q = modInverse (v[i], MOD);
        ll t = (s * q) % MOD;

        //p = (v[i]*v[i-1])/2
        ll p = ( (v[i] - 1 + MOD) % MOD * v[i]) % MOD;
        p = (p * modInverse (2, MOD) ) % MOD;

        // p has the number of different powers of i ... i.e. 1 + 2 + 3 + 4 .... v[i] = (v[i] * v[i-1])/2

        t = (t * p) % MOD;
        t = (t + 1) % MOD;

        // t has the number of divisors that can be formed using the prime corresponding to v[i]

        ans = (ans * t) % MOD;
    }


    cout << ans << endl;


    return 0;
}

