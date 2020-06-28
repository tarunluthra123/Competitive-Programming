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

void solve(){
    vector<vector<int>> ans;
    ll n;
    cin>>n;
    string a,b;
    cin>>a>>b;

    unordered_set<char> present;

    for (int i = 0; i < n; ++i) {
        if(a[i] < b[i]){
            cout << "-1\n";
            return;
        }
        present.insert(a[i]);
    }

    for (int i = 0; i < n; ++i) {
        if(present.find(b[i]) == present.end()) {
            cout << "-1\n";
            return;
        }
    }

    for (char c = 'z'; c >= 'a'; c--) {
        vector<int> s;
        for (int i = 0; i < n; ++i) {
            if(a[i] != c and b[i] == c){
                s.push_back(i);
            }
        }


        if(s.size()>0){
            for(int i = 0; i < n; i++){
                if(a[i] == c){
                    s.push_back(i);
                    break;
                }
            }

            ans.pb(s);
        }


        for(int i = 0; i < s.size(); i++){
            int idx = s[i];
            a[idx] = c;
        }
    }


    cout << ans.size() << endl;
    for(auto v: ans){
        cout << v.size() << " ";
        for(int j = 0; j < v.size(); j++){
            cout << v[j] << " ";
        }
        cout << endl;
    }


}

int main() { 
    sync;
    int testCases;
    cin >> testCases;
    while (testCases--) {
        solve();
    }

    return 0;
}
