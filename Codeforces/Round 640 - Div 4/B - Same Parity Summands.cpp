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
        ll n,k;
        cin>>n>>k;
        ll p = n-(k-1);
        if(p>0 and (p&1)){
            cout<<"YES\n";
            for (int i = 0; i < k-1; ++i) {
                cout<<"1 ";
            }
            cout << p << endl;
            continue;
        }

        ll q = n-2*(k-1);
        if(q>0 and q%2==0){
            cout<<"YES\n";
            for (int i = 0; i < k-1; ++i) {
                cout<<"2 ";
            }
            cout<<q<<endl;
            continue;
        } 

        cout<<"NO\n";
    }

    return 0;
}
