/*
http://codeforces.com/problemset/problem/1206/A

Choose Two Numbers
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array A, consisting of n positive integers a1,a2,…,an, and an array B, consisting of m positive integers b1,b2,…,bm.

Choose some element a of A and some element b of B such that a+b doesn't belong to A and doesn't belong to B.

For example, if A=[2,1,7] and B=[1,3,4], we can choose 1 from A and 4 from B, as number 5=1+4 doesn't belong to A and doesn't belong to B. However, we can't choose 2 from A and 1 from B, as 3=2+1 belongs to B.

It can be shown that such a pair exists. If there are multiple answers, print any.

Choose and print any such two numbers.

Input
The first line contains one integer n (1=n=100) — the number of elements of A.

The second line contains n integers a1,a2,…,an (1=ai=200) — the elements of A.

The third line contains one integer m (1=m=100) — the number of elements of B.

The fourth line contains m different integers b1,b2,…,bm (1=bi=200) — the elements of B.

It can be shown that the answer always exists.

Output
Output two numbers a and b such that a belongs to A, b belongs to B, but a+b doesn't belong to nor A neither B.

If there are multiple answers, print any.

Examples
inputCopy
1
20
2
10 20
outputCopy
20 20
inputCopy
3
3 2 2
5
1 5 7 7 9
outputCopy
3 1
inputCopy
4
1 3 5 7
4
7 5 3 1
outputCopy
1 1
Note
In the first example, we can choose 20 from array [20] and 20 from array [10,20]. Number 40=20+20 doesn't belong to any of those arrays. However, it is possible to choose 10 from the second array too.

In the second example, we can choose 3 from array [3,2,2] and 1 from array [1,5,7,7,9]. Number 4=3+1 doesn't belong to any of those arrays.

In the third example, we can choose 1 from array [1,3,5,7] and 1 from array [7,5,3,1]. Number 2=1+1 doesn't belong to any of those arrays.
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

istream& operator >>(istream& cin,vi &a) { ll i,n,x ; cin >> n ;  FOI(i,0,n-1) { cin >> x;   a.pb(x);  } return cin ; }

ll x,y;
template<class T> T gcd(T a,T b){ if(a==0) {x=0,y=1; return b;}T gc=gcd(b%a,a);T temp;temp=x;x=y-(b/a)*temp;y=temp;return gc;}

//(a^x)%m
ll po(ll a, ll x,ll m=MOD){ if(x==0){return 1;}ll ans=1;ll k=1;  while(k<=x) {if(x&k){ans=((ans*a)%m);} k<<=1; a*=a; a%=m; }return ans; }

bool find(ll c,vi &a,vi &b) {
    ll i ;
    FOI(i,0,a.size()-1) {
        if(a[i] == c) {
            return true;
        }
    }
    FOI(i,0,b.size()-1) {
        if(b[i] == c) {
            return true;
        }
    }

    return false;
}


int main() {
    sync;
    vi a,b;
    cin >> a >> b;
    ll i,j,n = a.size(),m = b.size();
    FOI(i,0,n-1) {
        FOI(j,0,m-1) {
            ll c = a[i] + b[j];
            if(!find(c,a,b)) {
                cout << a[i] << " " << b[j] ;
                return 0;
            }
        }
    }

    
    return 0;
}
