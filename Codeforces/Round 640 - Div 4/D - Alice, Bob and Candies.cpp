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
        int n;
        cin>>n;
        vi v(n);
        for (int i = 0; i < n; ++i) {
            cin>>v[i];
        }

        int i=0;
        int j=n-1;
        bool alice=true;

        ll a=0;
        ll b=0;
        ll c=0;

        ll prevAlice=0;
        ll prevBob=0;
        while(i<=j){
            if(alice){
                ll x=0;
                while(x<=prevBob and i<=j){
                    x+=v[i++];
                }
                a+=x;
                prevAlice=x;
            }
            else {
                ll x=0;
                while(x<=prevAlice and i<=j){
                    x+=v[j--];
                }
                b+=x;
                prevBob=x;
            }
            c++;
            alice=!alice;
        }

        cout<<c<<" " << a << " "<<b<<endl;

    }

    return 0;
}
