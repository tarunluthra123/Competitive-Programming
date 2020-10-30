/*
Roy and Trending Topics

https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/roy-and-trending-topics-1/

Roy is trying to develop a widget that shows Trending Topics (similar to Facebook) on the home page of HackerEarth Academy. 
He has gathered a list of N Topics (their IDs) and their popularity score (say z-score) from the database. Now z-score change everyday according to the following rules:

When a topic is mentioned in a 'Post', its z-score is increased by 50.
A 'Like' on such a Post, increases the z-score by 5.
A 'Comment' increases z-score by 10.
A 'Share' causes an increment of 20.
Now the Trending Topics are decided according to the change in z-score. One with the highest increment comes on top and list follows.
Roy seeks your help to write an algorithm to find the top 5 Trending Topics.
If change in z-score for any two topics is same, then rank them according to their ID (one with higher ID gets priority). It is guaranteed that IDs will be unique.

Input format:
First line contains integer N
N lines follow
Each contains 6 space separated numbers representing Topic ID, current z-score - Z, Posts - P, Likes - L, Comments - C, Shares - S

Output format:
Print top 5 Topics each in a new line.
Each line should contain two space separated integers, Topic ID and new z-score of the topic.

Constraints:
1 = N = 106 
1 = ID = 109 
0 = Z, P, L, C, S = 109

Sample Test Explanation:
enter image description here

Now sort them according to the change in z-score. Change in z-score for IDs 999, 1001, 1002, 1003 is 100, so sort them according to their ID (one with the higher ID gets priority). Similarly proceed further.

After you get the top 5 list of Topic IDs according to the above criteria, find the new z-score from the table for each ID.

SAMPLE INPUT 
8
1003 100 4 0 0 0
1002 200 6 0 0 0
1001 300 8 0 0 0
1004 100 3 0 0 0
1005 200 3 0 0 0
1006 300 5 0 0 0
1007 100 3 0 0 0
999 100 4 0 0 0

SAMPLE OUTPUT 
1003 200
1002 300
1001 400
999 200
1007 150

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

const double PI = 3.141592653589793;

template<class T>
using maxHeap = priority_queue<T>;
template<class T>
using minHeap = priority_queue<T,vector<T>,greater<T> >; 


ll x,y;
template<class T> 
T gcd(T a,T b){ if(a==0) {x=0,y=1; return b;}T gc=gcd(b%a,a);T temp;temp=x;x=y-(b/a)*temp;y=temp;return gc;}

//(a^x)%m
ll po(ll a, ll x,ll m=MOD){ if(x==0){return 1;}ll ans=1;ll k=1;  while(k<=x) {if(x&k){ans=((ans*a)%m);} k<<=1; a*=a; a%=m; }return ans; } 


int main(){
    sync;
    ll n,i ;
    cin >> n;
    maxHeap<pair<ll,pii> > pq ;
    FOI(i,0,n-1){
        lli id,z,p,l,c,s;
        cin >> id >> z >> p >> l >> c >> s;
        ll newScore = 50*p + 5*l + 10*c + 20*s ;
        ll change = newScore - z ;
        pq.push(mp(change,mp(id,newScore)));
    }

    FOI(i,0,4){
        cout << pq.top().second.first<<" "<<pq.top().second.second <<endl;
        pq.pop();
    }


    return 0;
}
