/*

https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/approximate/little-monk-and-root/

Little Monk and Root
Little Monk finally meets another favorite cricketer of his: Joe Root.

He wants to show Root the power of his magical function. Little Monk's function has the special ability to reduce a number to its one third value. Mathematically,  =  (x/3), where  is the smallest integer greater than or equal to x.

The Monk wants to reduce the career average of Root's career, so he decides to apply the function K number of times on various innings of his career. He can, of course, apply the function on the same innings multiple times. You're given the number of N innings and the runs scored by Root in his career, and you've to help reduce Root's final career average by applying Monk's special function K number of times on the innings of his career. And print his original average and his new career average.

Input format:
The first line contains two integers, N and K, denoting the number of innings of Root and the number of times the Monk can apply the magical function. The next line contains N space separated integers denoting the runs scored by Root in each innings.

Output format:
You've to print the initial career average of Joe Root, and the new average on the same line separated by a space. The difference till  in the answer will be accepted.

Constraints:
1 = N, K = 
K = N
1 =  = 

Note: You can safely assume that Joe Root was dismissed in every inning he played, so the role of a not-out in an innings is not important. Also, the difference till  in the answer will be accepted.

SAMPLE INPUT 
5 1
20 30 40 50 60
SAMPLE OUTPUT 
40.000000 32.000000
Explanation
The initial scores: 20, 30, 40, 50, 60.
The new scores after the function: 20, 30, 40, 50, 20.

Time Limit:	1.0 sec(s) for each input file.
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
#define PSET(x,y) fixed<<setprecision(y)<<(lf)(x)
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
using maxHeap = priority_queue<T>;
template<class T>
using minHeap = priority_queue<T,vector<T>,greater<T> >; 


ll x,y;
template<class T> T gcd(T a,T b){ if(a==0) {x=0,y=1; return b;}T gc=gcd(b%a,a);T temp;temp=x;x=y-(b/a)*temp;y=temp;return gc;}

//(a^x)%m
ll po(ll a, ll x,ll m=MOD){ if(x==0){return 1;}ll ans=1;ll k=1;  while(k<=x) {if(x&k){ans=((ans*a)%m);} k<<=1; a*=a; a%=m; }return ans; } 


int main() {
	sync;
	maxHeap<lf> pq;
    ll n,i,k;
    lf sum = 0 ; 
    cin >> n >> k;
    FOI(i,0,n-1){
        lf temp ;
        cin >> temp;
        sum += temp ;
        pq.push(temp);
    }
    FOI(i,0,k-1){
        lf x = pq.top();
        pq.pop();
        x = ceil(x/3);
        pq.push(x);
    }

    sum /= n;

    lf avg = 0;
    while(!pq.empty()){
        avg += pq.top();
        pq.pop();
    }

    avg /= n;

    cout << PSET(sum,6) << " " << PSET(avg,6);


	return 0;
}
