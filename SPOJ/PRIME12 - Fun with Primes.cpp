#include <bits/stdc++.h>
using namespace std;
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll  long long int
 
const int LIMIT = 87000000;
vector<bool> sieve(LIMIT,true);
vector<ll> primes;
 
void precompute()
{
    sieve[0] = sieve[1] = false;
 
    for (int i = 4; i < LIMIT; i += 2)
    {
        sieve[i] = false;
    }
 
    primes.push_back(2);
    for (ll i = 3; i < LIMIT; i += 2)
    {
        if (sieve[i])
        {
            primes.push_back(i);
            for (ll j = i * i; j  < LIMIT; j += i)
            {
                sieve[j] = false;
            }
        }
    }
}
 
 
int main() {
    sync;
    precompute();
    int testCases;
    cin >> testCases;
    while (testCases--) {
        int n;
        cin>>n;
        cout << primes[n]*primes[n] << '\n';
    }
    
    return 0;
}
 
