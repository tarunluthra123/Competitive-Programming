#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        int n;
        cin >> n;
        ll a[100000];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        ll cs = 0;
        ll ms = 0;

        for (int i = 0; i < n; i++)
        {
            cs += a[i];
            cs = max(cs, (ll)0);
            ms = max(ms, cs);
        }

        cout << ms << endl;
    }

    return 0;
}
