/*
MAXIMUM CIRCLES
There are n circles arranged on x-y plane. All of them have their centers on x-axis. You have to remove some of them, such that no two circles are overlapping after that. Find the minimum number of circles that need to be removed.


Input Format:
First line contains a single integer, n, denoting the number of circles. Next line contains two integers, c and r each, denoting the circle with radius r and center, (c,0).

Constraints:
1<=n<=10^5
|c|<=10^9
1<=r<=10^9

Output Format:
Print a single integer denoting the answer.

Sample Input:
4
1 1
2 1
3 1
4 1
Sample Output:
2
Explanation:
We can remove 1st and 3rd circle, or 2nd and 4th circle.

Time Limit: 2 sec
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool myCompare(pair<ll,ll> a,pair<ll,ll> b){
    return a.second < b.second ;
}

int main() {
    ll n;
    cin >> n;
    vector< pair<ll,ll> > v;
    for(ll i=0;i<n;i++){
        ll c,r;
        cin >> c >> r;
        ll s = c-r;
        ll e = c+r;
        v.push_back(make_pair(s,e));
    }
    sort(v.begin(),v.end(),myCompare) ;
   
    /*
    for(ll i=0;i<n;i++){
        cout << v[i].second << " ";
    }
    */

    ll count = 1;
    ll prev = v[0].second ;
    for(ll i=1;i<n;i++){
        if(v[i].first < prev){
            continue ;
        }
        count++;
        prev = v[i].second ; 
    }

    cout << (n - count) ; 

    return 0;
}

