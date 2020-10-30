//https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/xsquare-and-two-arrays/description/
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
	ll n, q;
	cin >> n >> q;
	vi a(n), b(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	vi x(n + 1), y(n + 1);
	bool flag = 0;
	x[0] = y[0] = 0;
	x[1] = a[0];
	y[1] = b[0];
	for (int i = 1; i < n; ++i) {
		x[i + 1] = x[i] + (flag ? a[i] : b[i]);
		y[i + 1] = y[i] + (flag ? b[i] : a[i]);
		flag = !flag;
	}

	// for (int i = 0; i < n + 1; ++i) {
	// 	cout << x[i] << " ";
	// }
	// cout << endl;
	// for (int i = 0; i < n + 1; ++i) {
	// 	cout << y[i] << " ";
	// }
	// cout << endl;

	while (q--) {
		ll t, l, r, a, b;
		cin >> t >> l >> r;
		if (t == 1) {
			if (l % 2 == 1) {
				cout << x[r] - x[l - 1];
			} else {
				cout << y[r] - y[l - 1];
			}
		} else {
			if (l % 2 == 0) {
				cout << x[r] - x[l - 1];
			} else {
				cout << y[r] - y[l - 1];
			}
		}
		cout << '\n';
	}

	return 0;
}
