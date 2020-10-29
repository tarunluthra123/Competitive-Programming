#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sync                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define MOD 1000000007

#define ff first
#define ss second

#define ll long long int
#define pii pair<ll, ll>
#define vi vector<ll>

int main()
{
    sync;
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        string s;
        cin >> s;

        ll n = s.size();
        ll ans = INT_MAX;
        ll a = ans;
        ll b = ans;
        ll j = INT_MAX;
        ll c = a;
        ll x,y;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                a = i;
            else if (s[i] == '2')
                b = i;
            else
                c = i;
            if (a != j and b != j and c != j)
            {
                x = min(a, min(b, c));
                y = max(a, max(b, c));
                ans = min(ans, y - x + 1);
            }
        }
        if (ans == j)
            cout << 0 << endl;
        else
            cout << ans << endl;
    }

    return 0;
}
