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

void printGrid(char grid[8][8]){
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout << grid[i][j] ;
        }
        cout<<'\n';
    }
}

void solve() {
    ll k;
    cin>>k;
    char grid[8][8];
    ll n=8;

    ll x=1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(x<=k){
                grid[i][j]='.';
                x++;
            } else {
                grid[i][j]='X';
            }
        }
    }
    grid[0][0]='O';
    printGrid(grid);
}

int main() {
    sync;
    int testCases, t = 1;
    cin >> testCases;
    while (testCases--) {
        // cout << "Case #" << t++ << ": ";
        solve();
        // cout << '\n';
    }

    return 0;
}
