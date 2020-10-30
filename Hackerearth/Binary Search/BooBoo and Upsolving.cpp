/*
https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/booboo-and-upsolving-circuits/

BooBoo and Upsolving
The hero of this story is a toddler named BooBoo. Inspired by the legendary competitive coder Gena, BooBoo has also started preparing to race to the top of the ranks.

BooBoo is going to practice N different problems in the exact given order over the next M days. For each problem, he writes down the amount of time  he will take to think and code the  problem (He is quite good at estimating!). Before starting on the problems, he took advice from experienced competitive programmers on his practice routine and almost all of them advised him to keep his daily load at the minimum possible and avoid over training.

Since BooBoo already has N problems to solve, he asks you to find the minimum time T such that training everyday for a time  is sufficient to solve all the N problems in M days.

Note : Unlike in real world, you cannot think on a problem on one day and solve it on the other day. You need to do it on the very same day!

Input Format:

The first line contains two space separated integers N and M. The next line contains N space separated integers denoting the time  required to solve the  problem.

Output Format:

The output consists of one integer, the minimum time T as described in the problem statement.

Constraints:

1 <= M < N <= 10^5
1 <= qi <= 10^12


Subtasks

20 points: .
80 points: Original Constraints

SAMPLE INPUT 
5 3
1 2 2 1 3
SAMPLE OUTPUT 
3
Explanation
By setting T = 3, we can solve 1st two questions on day 1, next two on day 2 and 5th one on day 3.
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

bool isValid(ll time,ll m,vi &v) {
	ll c = 1;
	ll sum = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		if(sum + v[i] > time) {
			sum = v[i];
			c++;
			if(c > m)
				return false;
		}
		else 
			sum += v[i];		
	}

	return true;
}


ll minTimeRequired(ll n,ll m,vi &v) {
	ll totalSum = 0;
	for (int i = 0; i < v.size(); ++i)
	{		
		totalSum += v[i];
	}
	ll limit = 1000000000000000000;
	ll s = 0;
	ll e = limit;//min(totalSum,limit);
	ll ans = -1;
	while(s <= e) {
		ll mid = (s+e)/2;
		//cout << mid << endl;
		if(isValid(mid,m,v)) {
			ans = mid;
			e = mid-1;
		}
		else {
			s = mid+1;
		}
	}

	return ans;
}


int main() { 
	sync;
	ll n,m;
	cin >> n >> m;
	vi v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];		
	}

	cout << minTimeRequired(n,m,v) ;

	return 0;
}					
