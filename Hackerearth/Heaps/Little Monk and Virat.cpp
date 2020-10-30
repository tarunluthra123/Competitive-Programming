/*
https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/little-monk-and-virat/

Little Monk and Virat
Little Monk also met who he thinks is the new God of Indian cricket: Virat Kohli. Now Monk is extremely fond of Kohli -- not just as a T20 player, but a player in all formats. He loves the statistics involved in Kohli's career.

Little Monk knows that Kohli has played N matches in all three formats of his career, ODI, T20 and Test Cricket. He wants to show-off his knowledge about Kohli's career so he decides to answer Q questions asked by Kohli. Kohli gives the Monk three different arrays with N numbers each denoting the runs in the ith ODI match, ith Test Match and ith T-20 match respectively.

The value of Kohli's ith match would be the sum of his score in the ith T-20 match, ith Test match and ith ODI match. Kohli knows that Monk is extremely quick at finding the k th smallest value of all his innings, so he twists his query a bit. He asks the Monk to delete the kth smallest value once that is answered by the Monk. If Kohli comes up with a number k which is greater than the number of matches remaining in Kohli's career, the Monk should say that the answer is 1

So much complication confuses the Little Monk and he asks for your help!

Input format:
The first line contains an integer N, which denotes the number of matches played by Virat Kohli. The next three lines contain N integers each denoting the number of runs scored in ODI, T20 and Test respectively. The next line contains an integer Q, denoting the number of questions Virat is going to ask. The next Q lines contain an integer K, denoting the Kth smallest value which the Monk has to answer.

Output format: 
Print answer to each query in a new line. In case of an invalid query, print 1.

Constraints:
1 = N =  
1 = Ni =  
1 = K =  
1 = Qi = 

Note: The test data contains a lot of I/O operations, it is thus recommended to use faster input / output mechanisms.

SAMPLE INPUT 
5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
3
1
3
11
SAMPLE OUTPUT 
3
12
-1
Explanation
The N values are: 3, 6, 9, , . So, the first smallest is 3, and now the new value array is: 6, 9, , , so the third smallest value now is . In the third query is invalid because the value array contains only 3 numbers, and we're asking the Monk to find the th smallest number, so the answer is 1.
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
    minHeap<ll> pq;
    ll n ;
    cin >> n;
    vi v1(n),v2(n),v3(n);
    ll i;
    FOI(i,0,n-1) {
    	cin >> v1[i];
    } 
    FOI(i,0,n-1) {
    	cin >> v2[i];
    }
    FOI(i,0,n-1) {
    	cin >> v3[i];
    }
    FOI(i,0,n-1) {
    	pq.push(v1[i]+v2[i]+v3[i]);
    }
    int testCases;
    cin >> testCases;
    while (testCases--) {
    	ll k;
    	cin >> k;
    	if(k > pq.size()) {
    		cout << -1 << endl;
    		continue;
    	}
    	vi v;
    	FOI(i,1,k-1){
    		v.pb(pq.top());
    		pq.pop();
    	}	
    	cout << pq.top();
    	pq.pop();
    	FOI(i,0,v.size()-1){
    		pq.push(v[i]);
    	}
    	cout << endl;
    }

    
    return 0;
}
