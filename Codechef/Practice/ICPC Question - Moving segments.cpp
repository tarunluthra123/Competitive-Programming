#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007

#define ff first
#define ss second

#define ll  long long
#define pii pair<ll, ll>
#define vi  vector<ll>

bool cmp(pii a,pii b){return a.ss<b.ss;}
bool overlap(pair<ll,ll> a, pair<ll, ll> b)
{
	ll l1=a.first;
	ll r1=a.second;
	ll l2=b.first;
	ll r2=b.second;
	
	if(r1>=l2)return 1;
	return 0;
}

int main() { 
	sync;
	int testCases;
	cin >> testCases;
	while (testCases--) {
		int n;
		cin>>n;
		ll l,r,v;
		map<ll, vector<pii> > speed;
		for (int i = 0; i < n; ++i) {
			cin>>l>>r>>v;
			speed[v].pb({l,r});
		}


		bool ans=true;
		int c=0;

		for(auto x:speed){
			auto arr = x.ss;
			sort(arr.begin(), arr.end(),cmp);
			for(int i=0;i<arr.size()-1;i++){
			    c=0;
				for(int j=i+1;j<arr.size();j++){
					if(overlap(arr[i],arr[j])){
						c++;
					}
					if(c>1){
						ans=false;
						break;
					}
				}
				if(!ans)break;
			}

			if(!ans)break;
		}

		if(ans)
			cout<<"YES\n";
		else
			cout<<"NO\n";

	}

	return 0;
}
