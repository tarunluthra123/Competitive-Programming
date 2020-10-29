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
        ll k;
        cin>>k;
        vi a(n);
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        vi b(n);
        for (int i = 0; i < n; ++i) {
            cin>>b[i];
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int i=0;
        int j=n-1;
        ll sum=0;
        while(k-- and b[j]>a[i]){
            sum += b[j];
            j--;
            i++;
        }
        for (; i < n; ++i)
        {
            sum += a[i];
        }

        cout << sum << '\n';
    }

    return 0;
}
