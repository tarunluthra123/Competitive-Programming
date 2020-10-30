/*
Monk and Multiplication
The Monk learned about priority queues recently and asked his teacher for an interesting problem. So his teacher came up with a simple problem. He now has an integer array A. For each index i, he wants to find the product of the largest, second largest and the third largest integer in the range [1,i].
Note: Two numbers can be the same value-wise but they should be distinct index-wise.

Input:
The first line contains an integer N, denoting the number of elements in the array A.
The next line contains N space separated integers, each denoting the ith integer of the array A.

Output:
Print the answer for each index in each line. If there is no second largest or third largest number in the array A upto that index, then print "-1", without the quotes.

Constraints:
1 <= N <= 100000
0 <= A[i] <= 1000000

SAMPLE INPUT 
5
1 2 3 4 5
SAMPLE OUTPUT 
-1
-1
6
24
60
Explanation
There are 5 integers 1,2,3,4 and 5.
For the first two indexes, since the number of elements is less than 3, so -1 is printed.
For the third index, the top 3 numbers are 3,2 and 1 whose product is 6.
For the fourth index, the top 3 numbers are 4,3, and 2 whose product is 24.
For the fifth index, the top 3 numbers are 5,4 and 3 whose product is 60.
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
    ll n,i=0;
    cin >> n;
    ll temp ;
    minHeap<ll> pq;
    FOI(i,0,n-1){
        cin >> temp;
        if(i < 2){
            pq.push(temp);
            cout << "-1\n";
            continue ;
        }
        else if(i == 2){
            pq.push(temp);
        }
        else {
            if(temp > pq.top()){
                pq.pop();
                pq.push(temp);
            }
        }
        ll first = pq.top();    pq.pop();
        ll second = pq.top();   pq.pop();
        ll third = pq.top();    pq.pop();
        cout << first*second*third << endl;
        pq.push(first);
        pq.push(second);
        pq.push(third);
    }


    return 0;
}
