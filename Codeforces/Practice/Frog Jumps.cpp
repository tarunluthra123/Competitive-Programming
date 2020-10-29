//https://codeforces.com/contest/1324/problem/C
#include <bits/stdc++.h>
using namespace std;

#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main() {
    sync;

    int testCases;
    cin >> testCases;
    while (testCases--) {
        string s;
        cin>>s;

        vector<int> v(1);
        v[0] = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if(s[i] == 'R') 
            {
                v.push_back(i+1);
            }
        }

        v.push_back(s.size()+1);
        int ans = 0;

        for (int i = 1; i < v.size(); ++i)
        {
            ans = max(ans, v[i]-v[i-1]);
        }

        cout << ans << "\n";
    }

    return 0;
}
