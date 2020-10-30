/*
https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/monk-and-search-2/

Monk and Search
Monk and his friend Micro are on a quest to find the answer of Life, Universe and Everything. In order to complete it they need to answer Q queries on an array A having N integers. The queries can be of following two types:
0 x Find the number of numbers in A which are not less than x.
1 x Find the number of numbers in A which are greater than x.
Help them complete the quest and be back in time for the next Code Monk Challenge.

Input Format:
First line consists of a single integer denoting N.
Second line consists of N space separated integers denoting the array A.
Third line consists of a single integer denoting Q.
Each of the following Q lines consists of a query of one of the given two types.

Output Format: 
For each query print the required answer in new line.

Constraints:
1<=N<=10^5
1<=Q<=3*10^5
1<=A[i]x<=10^9
 

SAMPLE INPUT 
4
1 2 3 4
3
0 5
1 3
0 3
SAMPLE OUTPUT 
0
1
2
Explanation
For first query, there are no numbers in the array which are not less than 5 so answer for first query is 0. 
For second query, 4 is the only number greater than 3, so answer is 1.
For third query, 3 and 4 are the numbers in array which are not less than 3, so answer is 2.
*/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define FOI(i, a, n) for( i = int(a); i <= int(n); i++)
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007

#define ll  long long int
#define pii pair<ll, ll>
#define vi  vector<ll>

bool strictlyGreater(ll a,ll b) {
    return a<b;
}

bool greaterThanEqualTo(ll a,ll b) {
    return a<=b;
}

ll findInArray(vi &v,ll k,bool (*compare)(ll,ll)) {
    ll s = 0;
    ll e = v.size()-1;
    ll ans = -1;
    if(compare(v[e],k)) {
        return e;
    }

    while(s<=e) {
        ll mid = (s+e)/2;
        if(compare(v[mid],k)) {
            
            s = mid+1;
         
            ans = mid;
        }
        else {
            e = mid-1;
        }
    }
    return ans;
}

int main() { 
    sync;
    ll n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end())

    int testCases;
    cin >> testCases;
    while (testCases--) {
        ll q;
        cin >> q;
        ll k;
        cin >> k;

        ll index ;
        if(q==0)
            index = findInArray(v,k,strictlyGreater);
        else 
            index = findInArray(v,k,greaterThanEqualTo);

        cout << n-index-1 << endl;
    }

    return 0;
}
