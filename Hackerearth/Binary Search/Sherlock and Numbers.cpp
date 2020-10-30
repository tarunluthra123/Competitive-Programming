/*
https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/sherlock-and-numbers/

Sherlock and Numbers
Watson gives to Sherlock a bag of numbers [1, 2, 3 ... N] and then he removes K numbers A1, A2 ... AK from the bag. He now asks Sherlock to find the P'th smallest number in the bag.

Input
First line contains T, the number of test cases. Each test case consists of N, K and P followed by K integers in next line denoting the array A.

Output
For each test case, print P'th smallest number in the bag. If no such number exists output -1.

Constraints
1 = T = 10
20% testdata: 1 = N = 103
20% testdata: 1 = N = 105
60% testdata: 1 = N = 109
0 = K = min(N, 105)
1 = P = N

Note: Large input files. Use scanf instead of cin.

SAMPLE INPUT 
2
4 1 2
1
5 2 4
1 3
SAMPLE OUTPUT 
3
-1
Explanation
Test case 1: Remaining numbers are [2, 3, 4]. 3 is the 2nd smallest remaining numbers.

Test case 2: Remaining numbers are [2, 4, 5]. 4th smallest remaining number doesn't exist.
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
	sync;
	int testCases;
	cin >> testCases;
	while (testCases--) 
	{
		ll n,k,p;
		cin >> n >> k >> p;
		ll a,c = 0;

		for (int i = 0; i < k; ++i)
		{
			cin >> a;
			if (a <= p+c)
			{
				c++;
			}
		}
		if (k + p <= n)
		{
			cout << p+c;
		}
		else
			cout << -1;

		cout << endl;
	}

	return 0;
}
