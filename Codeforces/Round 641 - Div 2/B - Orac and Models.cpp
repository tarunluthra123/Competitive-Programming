#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007

#define ff first
#define ss second

#define ll  long long int
#define pii pair<ll, ll>
#define vi  vector<ll>

int main() { 
    sync;
    int testCases;
    cin >> testCases;
    while (testCases--) {
        ll n;
        cin>>n;
        vi v(n+1);
        for (int i = 1; i <= n; ++i) {
            cin>>v[i];
        }

        vi dp(n+1,1);
        for (int i = 1; i <= n; ++i) {
            for (int j = i*2; j <= n; j += i) {
                if(v[j] > v[i]) {
                    dp[j] = max(dp[j], dp[i]+1);
                }
            }
        }

        ll ans = 0;

        for (int i = 0; i <= n; ++i) {
            ans = max(ans, dp[i]);
        }

        cout << ans << '\n';
    }

    return 0;
}
