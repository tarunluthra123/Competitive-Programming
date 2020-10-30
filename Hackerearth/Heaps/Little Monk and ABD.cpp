/*
https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/little-monk-and-abd/

Little Monk and ABD
Little Monk meets his another favorite cricketer this time: A-B-D. Little Monk says that he is the biggest fan of ABD. ABD does not believe the Monk at all, and asks him to prove how much does he know about ABD's career.

So, ABD tells the Monk that given his latest N innings, he is going to ask him Q number of questions about his career which would involve questions of two types:

Find the kth smallest score of his career - denoted by a query of type: "k S", where k is an integer and S denotes smallest.
Find the kth largest score of his career - denoted by a query of type: "k L", where k is an integer and L denotes largest.
Help Little Monk answer as many queries as possible!

Input format:
The first line contains an integer N, which denotes the number of innings played by ABD which have to be dealt by The Monk. The next line contains N space separated integers denoting the number of scores made by ABD. The next line contains an integer Q denoting the number of questions ABD is going to be asking. After that, the next Q lines will contain a query like the ones mentioned above.

Output format: 
Print the required answer for each query on a newline.

Constraints:
1 = N =  
1 = Q =  
1 = K =  
1 = Ni = 

SAMPLE INPUT 
5
1 2 3 4 5
3
3 L
3 S
1 L
SAMPLE OUTPUT 
3
3
5
Explanation
 largest score is 3.
 smallest score is 3.
 largest score is 5.
*/

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

#define ff first
#define ss second

const double PI = 3.141592653589793;

template<class T>
using maxHeap = priority_queue<T>;
template<class T>
using minHeap = priority_queue<T,vector<T>,greater<T> >;

istream& operator >>(istream& cin,vi &a) { ll i,n,x ; cin >> n ;  FOI(i,0,n-1) { ll x;  cin >> x;   a.pb(x);  } return cin ; }

ll x,y;
template<class T> T gcd(T a,T b){ if(a==0) {x=0,y=1; return b;}T gc=gcd(b%a,a);T temp;temp=x;x=y-(b/a)*temp;y=temp;return gc;}

//(a^x)%m
ll po(ll a, ll x,ll m=MOD){ if(x==0){return 1;}ll ans=1;ll k=1;  while(k<=x) {if(x&k){ans=((ans*a)%m);} k<<=1; a*=a; a%=m; }return ans; }


int main() {
    sync;
    ll n ;
    cin >> n;
    vi v;
    while(n--) {
    	ll x;
    	cin >> x;
    	v.pb(x);
    }
    sort(ALL(v));
    int testCases;
    cin >> testCases;
    while (testCases--) {
    	ll k;
    	char ch;
    	cin >> k >> ch;
    	if(ch == 'L') {
    		cout << v[v.size()-k];
    	}	
    	else {
    		cout << v[k-1];
    	}
    	cout << endl;
    }

    
    return 0;
}
