//https://www.codechef.com/MAY20B/problems/COVID19
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define SZ(x) ((int)(x.size()))
#define FOI(i, a, n) for( i = int(a); i <= int(n); i++)
#define FOD(i, a, n) for( i = int(a); i >= int(n); i--)
#define IN(x, y) ((y).find(x) != (y).end())
#define ALL(t) t.begin(),t.end()
#define MSET(tabl,i) memset(tabl, i, sizeof(tabl))
#define PSET(x,y) fixed<<setprecision(y)<<lf(x)
#define DBG(c) cout << #c << " = " << c << endl;
#define RTIME ((double)clock()/(double)CLOCKS_PER_SEC)
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007

#define ll  long long int
#define lli long long int
#define ull unsigned long long int
#define lf  long double
#define pii pair<lli, lli> 
#define pll pair<lli, lli>
#define vi  vector<ll>

const double PI = 3.141592653589793;

template<class T>
using maxPQ = priority_queue<T>;
template<class T>
using minPQ = priority_queue<T,vector<T>,greater<T> >; 


ll x,y;
ll gcd(ll a,ll b){ if(a==0) {x=0,y=1; return b;}ll gc=gcd(b%a,a);ll temp;temp=x;x=y-(b/a)*temp;y=temp;return gc;}

//(a^x)%m
ll fastPow(ll a, ll x,ll m=MOD){ if(x==0){return 1;}ll ans=1;ll k=1;  while(k<=x) {if(x&k){ans=((ans*a)%m);} k<<=1; a*=a; a%=m; }return ans; } 


ll modInverse (ll A, ll M = MOD) { gcd(A, M);  return (x % M + M) % M; }


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

    	int group = 1;
    	unordered_map<int,int> m;
    	m[1]=1;

    	for (int i = 1; i < n; ++i) {
    		if(v[i]-v[i-1]>2){
    			group++;
    		}
    		m[group]++;
    	}

    	int maxAns = 1;
    	int minAns = n;
    	for (int i = 1; i <= group; ++i) {
    		maxAns = max(m[i], maxAns);
    		minAns = min(m[i],minAns);
    	}
    	
    	cout << minAns << " " << maxAns << '\n';
    }
    
    return 0;
}
