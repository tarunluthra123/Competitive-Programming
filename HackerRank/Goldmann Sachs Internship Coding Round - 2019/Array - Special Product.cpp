#include <bits/stdc++.h>
using namespace std;

#define FOI(i, a, n) for( i = int(a); i <= int(n); i++)
#define FOD(i, a, n) for( i = int(a); i >= int(n); i--)

#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define ll  long long int
#define vi  vector<ll>

vi specialProduct(vi v) {
    ll n = v.size();
    vi leftProduct(n+1);
    vi rightProduct(n+1);

    ll i;

    leftProduct[0] = 1;
    FOI(i,1,n) {
        leftProduct[i] = leftProduct[i-1]*v[i-1];
    }

    rightProduct[n] = 1;
    FOD(i,n-1,0) {
        rightProduct[i] = rightProduct[i+1]*v[i];
    }


    /*
    FOI(i,0,n) {
        cout << leftProduct[i] << " ";
    }
    cout << endl;
    FOI(i,0,n) {
        cout << rightProduct[i] << " ";
    }
    cout << endl;
    */

    vi ans(n);
    FOI(i,0,n-1) {
        ans[i] = leftProduct[i]*rightProduct[i+1];
    }

    return ans;
}



int main() {
    sync;
    ll n;
    cin >> n;
    vi v(n);
    ll i;
    FOI(i,0,n-1) {
        cin >> v[i];
    }
    
    vi ans = specialProduct(v);

    FOI(i,0,n-1) {
        cout << ans[i] << '\n' ;
    }

    
    return 0;
}
