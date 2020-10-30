/*
https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/pk-and-special-array-operation-1-7bd52ad1/

Special Array Operation
You are given an array A of size N. You can perform an operation in which you will remove the largest and the smallest element from the array and add  their difference back into the array. So, the size of the array will decrease by 1 after each oepration. You are given Q tasks and in each task, you are given an integer K. For each task, you have to tell sum of all the elements in the array after K operations.

Input:

First line contains two space-separated integers N and Q, denoting the number of elements in array and number of queries respectively.

Next line contains N space-separated integers denoting elements of the array.

Next Q lines contain a single integer K.

Output:

For each task, print answer in a new line.

Constraints:

2 <= N <= 105

1 <= Q <= 105

0 <= A[i] <= 109

0 <= K < N

SAMPLE INPUT 
5 2
3 2 1 5 4
1
2
SAMPLE OUTPUT 
13
9
Explanation
After 1st operation, the array will become, A = [3,2,4,4]. So, sum of elements = 13.

After 2nd operation, the array will become, A = [3,2,4]. So, sum of elements = 9.
*/

//C++ Template
//By Tarun Luthra
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
    minHeap<ll> mn;
    maxHeap<ll> mx;
    ll n,q;
    cin >> n >> q;
    ll sum = 0 ;
    while(n--) {
    	ll x;
    	cin >> x;
    	sum += x;
    	mx.push(x);
    	mn.push(x);
    }

    ll i,ans[100005] = {0};
    ans[0] = sum;
    FOI(i,0,100000) {
    	ll x = mn.top();
    	mn.pop();
    	ll y = mx.top();
    	mx.pop();
    	ll z = y-x;
    	mn.push(z);
    	mx.push(z);
    	sum = sum - x - y + z;
    	ans[i+1] = sum;
    }

    while(q--) {
    	ll k ;
    	cin >> k;
    	cout << ans[k] << endl;
    }

    
    return 0;
}

