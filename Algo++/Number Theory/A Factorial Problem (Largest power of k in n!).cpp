/*
A FACTORIAL PROBLEM
Mike found an interesting problem. In this problem you are given two integers, n and k. You need to find the the maximum value of x, such that, n! % kx = 0.


Input Format:
First line contains number of test cases, T. Each test case contains two integers each, n and k.

Constraints:
1<=T<=20
1<=n<=10^8
2<=k<=10^8

Output Format:
Print the value of x for each test case.

Sample Input:
2
5 2
1000 2
Sample Output:
3
994
Explanation:
In the first test case, n = 5 and k = 2. So, n! = 120. n! % 2^0 = 0, n! % 2^1 = 0, n! % 2^2 = 0, n! % 2^3 = 0, n! % 2^4 = 8, n! % 2^5 = 24, n! % 2^6 = 56, n! % 2^7 = 120. So, the answer should be 3.

Time Limit: 1 sec
*/
#include <bits/stdc++.h> 
using namespace std; 
#define ll long long int


//Using Legendre's formula 
ll findPowerOfP(ll n, ll p) { 
	ll count = 0; 
	ll res = p; 
	while (res <= n) { 
		count += (n / res); 
		res = res * p; 
	} 
	return count; 
} 

// returns all the prime factors of k 
vector<pair<ll,ll> > primeFactorsofK(ll k) { 
	// vector to store all the prime factors along with their number of occurrence in factorization of k 
	vector<pair<ll,ll> > ans; 

	for(ll i = 2; k != 1; i++) { 
		if (k % i == 0) { 
			ll count = 0; 
			while (k % i == 0) { 
				k = k / i; 
				count++; 
			} 

			ans.push_back(make_pair(i, count)); 
		} 
	} 
	return ans; 
} 

// Returns largest power of k that divides n! 
ll largestPowerOfK(ll n, ll k) { 
	vector< pair<ll, ll> > vec; 
	vec = primeFactorsofK(k); 
	ll ans = INT_MAX; 
	for (ll i = 0; i < vec.size(); i++) {
		// calculating minimum power of all the prime factors of k 
		ans = min(ans, findPowerOfP(n, vec[i].first) / vec[i].second); 
    }


	return ans; 
} 


int main() {   
    int testCases;
    cin >> testCases;
    while(testCases--){
        ll n,k;
        cin >> n >> k;
        cout << largestPowerOfK(n,k) << endl;
    } 

	return 0; 
} 

