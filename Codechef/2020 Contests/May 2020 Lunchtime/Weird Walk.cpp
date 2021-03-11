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
        vi a(n),b(n);
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin>>b[i];
        }

        ll i=0,j=0,p=0,q=0,weird=0;

        while(i<n and j<n){
            if(p==q and a[i]==b[j]){
                weird+=a[i];
                p+=a[i];
                q+=a[i];
                i++;
                j++;
            } else {
                p+=a[i];
                q+=b[j];
                i++;
                j++;
            }
        }

        cout<<weird<<'\n';
    }

    return 0;
}
