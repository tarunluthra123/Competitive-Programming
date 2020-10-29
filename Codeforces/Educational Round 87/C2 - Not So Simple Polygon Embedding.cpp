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

const double PI = 3.1415927;

int main() { 
    sync;
    int testCases;
    cin >> testCases;
    while (testCases--) {
        ll n;
        cin>>n;
        double ang = PI/(2*n);
        double ans = cos(ang/2)/sin(ang);
        cout << fixed << setprecision(10) << ans  << endl;
    }
    

    return 0;
}
