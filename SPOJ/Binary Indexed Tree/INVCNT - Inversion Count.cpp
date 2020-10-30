/*
https://www.spoj.com/problems/INVCNT/

INVCNT - Inversion Count
Let A[0...n - 1] be an array of n distinct positive integers. If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A. Given n and an array A your task is to find the number of inversions of A.

Input
The first line contains t, the number of testcases followed by a blank space. Each of the t tests start with a number n (n <= 200000). Then n + 1 lines follow. In the ith line a number A[i - 1] is given (A[i - 1] <= 10^7). The (n + 1)th line is a blank space.

Output
For every test output one line giving the number of inversions of A.

Example
Input:
2

3
3
1
2

5
2
3
8
6
1


Output:
2
5
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

vector<ll> coordinateCompress(const vector<ll> &v) {
    set<ll> s;
    unordered_map<ll,ll> m;
    for(int i=0;i<v.size();i++) {
        s.insert(v[i]);
    }

    for(int i=1; !s.empty() ; i++) {
        m[*s.begin()] = i;
        s.erase(s.begin());
    }

    vector<ll> ans(v.size());
    for(int i=0;i<ans.size();i++) {
        ans[i] = m[v[i]];
    }

    return ans;
}

vector<ll> BIT;

void update(int i,int inc) {
    while(i < BIT.size()) {
        BIT[i] += inc;
        i += i&(-i);
    }
}

ll query(int i) {
    ll sum = 0 ;
    while(i > 0) {
        sum += BIT[i];
        i -= i&(-i);
    }
    return sum;
}

ll inversionCount(const vector<ll> &v) {
    BIT.clear();
    BIT.resize(v.size()+5,0);
    ll ans = 0 ;

    for(int i=v.size()-1;i >= 0 ; i--) {
        ans += query(v[i]);
        update(v[i],1);
    }

    return ans;
}

int main() {
    sync;
    int testCases;
    cin >> testCases;
    while(testCases--) {
        int n;
        cin >> n;
        vector<ll> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }

        v = coordinateCompress(v);

        // for(int i=0;i<n;i++) {
        //     cout << v[i] << " ";
        // }
        // cout << endl;

        cout << inversionCount(v) << endl;
    }

    return 0;
}

