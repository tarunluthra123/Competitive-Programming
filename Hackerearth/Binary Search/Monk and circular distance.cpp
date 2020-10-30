/*
https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/circular-distance-3/description/

Monk and circular distance
Its time for yet another challenge, and this time it has been prepared by none other than Monk himself for Super-Hardworking Programmers like you. So, this is how it goes:

Given N points located on the co-ordinate plane, where the ith point is located at co-ordinate ,(x[i],y[i]) you need to answer q queries.

In the ith query, you shall be given an integer r[i], and considering you draw a circle centered at the origin with radius r, you need to report the number of points lying inside or on the circumference of this circle.

For each query, you need to print the answer on a new line.

Input Format :

The first line contains a single integer N denoting the number of points lying on the co-ordinate plane. Each of the next N lines contains 2 space separated
 integer sx[i]  and y[i], denoting the x and y co-ordintaes of the point.

The next line contains a single integer q, denoting the number of queries. Each of the next q lines contains a single integer, r where the integer on the  
line denotes the parameters of the  query .

Output Format :

For each query, print the answer on a new line.

Constraints :
1<=N<=10^5
-10^9 <= x[i],y[i] <=10^9
1<=q<=10^5
0 <= r[i] <= 10^18


SAMPLE INPUT 
5
1 1
2 2
3 3
-1 -1
4 4
2
3
32
SAMPLE OUTPUT 
3
5

*/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007

#define ff first
#define ss second

#define ll  long long int
#define pii pair<ll, ll>
#define vi  vector<ll>

bool myCompare(double a,double b) {
    return a<=b;
}

int main() { 
    sync;
    ll n;
    cin >> n;
    vector<double> v(n);
    for (ll i = 0; i < n; ++i) {
        ll x,y;
        cin >> x >> y;
        double dist = sqrt(x*x + y*y);
        v[i] = dist;
    }

    sort(v.begin(), v.end());

    int testCases;
    cin >> testCases;
    while (testCases--) {
        ll r;
        cin >> r;
        ll index = lower_bound(v.begin(), v.end(),r,myCompare) - v.begin();

        cout << index << endl;

    }

    return 0;
}
