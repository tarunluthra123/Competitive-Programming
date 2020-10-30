/*
https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/haunted/

Haunted
The king of ghosts is really disappointed when he sees that all the human beings on Planet Earth have stopped fearing the ghost race. He knows the reason for this. The existing ghost race has become really lazy and has stopped visiting Planet Earth to scare the human race. Hence, he decides to encourage the entire ghost race into scaring the humans by holding a competition. The king, however, never visits Planet Earth.

This competition will go on for N days. Currently, there are a total of M ghosts (apart from the king) existing in the ghost race such that :
- The youngest ghost is 1 year old.
- The oldest ghost is M years old.
- No two ghosts have the same age.
- The age of each and every ghost is a positive integer.

On each day of the competition, ghosts have to visit Planet Earth to scare people. At the end of each day, a "Ghost of the Day" title is awarded to the ghost who scares the most number of humans on that particular day. However, the king of ghosts believes in consistency. Once this title has been given, the ghost who has won the most number of such titles until that particular moment is presented with a "Consistency Trophy". If there are many such ghosts, the oldest among them is given the trophy. Note that this "Title Giving" and "Trophy Giving" happens at the end of each day of the competition.

You will be given the age of the ghost who won the "Ghost of the Day" title on each day of the competition. Your job is to find out the age of the ghost who was awarded with the "Consistency Trophy" on each day of the competition.

Input
The first line consists of 2 space separated integers N and M. The next line consists of N space separated integers such that the ith integer denotes the age of the ghost who was awarded with the "Ghost of the Day" title on the ith day of the competition.

Output
Print N lines. The ith line should contain 2 space separated integers such that the first integer denotes the age of the ghost who was awarded with the "Consistency Trophy" on the ith day and the second integer denotes the number of "Ghost of the Day" titles won by this ghost until the end of the ith day of the competition.

Constraints
1 = N = 105
1 = M = 109

SAMPLE INPUT 
7 5
1 3 1 3 2 2 2
SAMPLE OUTPUT 
1 1
3 1
1 2
3 2
3 2
3 2
2 3
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
    ll m,n,i;
    cin>>n>>m;

    maxHeap<pii> pq;
    unordered_map<ll,ll> freq;
    
    while(n--) {
    	ll x;
    	cin >> x;
    	if(freq.find(x)==freq.end()) {
    		freq[x] = 1;
    	}
    	else {
    		freq[x]++;
    	}
    	pq.push(mp(freq[x],x));  	
    	pii top = pq.top();
    	cout << top.ss << " " << top.ff << endl;
    }


    
    return 0;
}
