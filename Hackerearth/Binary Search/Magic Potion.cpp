/*
https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/magic-potion-d54349f9/

Magic Potion
Shruti loves to play with Array. She would always be busy doing some random operation with her array. Today she got to know about Magic Potion. A Magic Potion is a special power that allows you to remove one element from your array either from the start or the end. After spending some time on Magic Potion she decided to use it on her arrays.

Shruti has an array of size N. She calls an array a Good array if the sum of the array is exactly K. She wants to apply Magic Potion on her array so that she could get a Good array. She wants to find the count of all the Good arrays that could be formed from the given initial array by applying Magic Potion on them any number of times. She is also interested in finding out the minimum Magic Potion required to form a single Good array. Since she is already quite busy she asks you for help.

Input:

The first line contains 2 integers N and K denoting the size of the array and the sum value required for an array to be Good.This is followed by N-space separated integers that denote the array.

Output:

Print two space-separated integers where the first integers denote the count of all possible Good arrays while the second integers indicate minimum Magic Potion required for a Good array.

Constraints:

1  N  105

1  K  1012

0  Ai  109

Note:

A Good Array will always exist.

SAMPLE INPUT 
3 3
1 2 3
SAMPLE OUTPUT 
2 1
Explanation
The two possible Good arrays are: {1, 2} and {3}. Magic Potion required to form {1, 2} is 1 while required to form {3} is 2.

So the final answer is 2 and 1.
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

int main()
{
    ll n, k;
    cin >> n >> k;
    vi v(n);

    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }

    ll i = 0;
    ll j = 0;
    ll maxLen = 0; 
    ll sum = 0;

    ll c = 0;

    for (; i < n; i++) {
        sum += v[i];

        while (sum > k) {
            sum -= v[j];
            j++;
        }

        if (sum == k) {
            maxLen = max (i - j + 1, maxLen);
        }
    }

    map<ll,ll> m;
    m[0] = 1;
    sum = 0, i = 0;
    for (; i < n; i++) {
        sum += v[i];
        c += m[sum-k];
        m[sum]++;
    }
   
    cout << c << " " << n - maxLen;

    return 0;
}

