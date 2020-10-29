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
        ll a,b,c;
        cin>>a>>b>>c;
        string res="";
        if (b == 0) {
            if (a != 0) {
                cout << string(a + 1, '0') << endl;
            } else {
                cout << string(c + 1, '1') << endl;
            }
            continue;
        }
        else{
            res=string(c,'1');
            if(b>0){
                b--;
                res+="1";
            }
            res += string(a,'0');
            for (int i = 0; i < b+1; ++i) {
                res += (i&1?"1":"0");
            }
            cout<<res;
        }
        cout<<endl;
    }

    return 0;
}
