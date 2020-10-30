/*
ELIS - Easy Longest Increasing Subsequence
Given a list of numbers A output the length of the longest increasing subsequence. An increasing subsequence is defined as a set {i0 , i1 , i2 , i3 , ... , ik} such that 0 <= i0 < i1 < i2 < i3 < ... < ik < N and A[ i0 ] < A[ i1 ] < A[ i2 ] < ... < A[ ik ]. A longest increasing subsequence is a subsequence with the maximum k (length).

i.e. in the list {33 , 11 , 22 , 44}

the subsequence {33 , 44} and {11} are increasing subsequences while {11 , 22 , 44} is the longest increasing subsequence.

Input
First line contain one number N (1 <= N <= 10) the length of the list A.

Second line contains N numbers (1 <= each number <= 20), the numbers in the list A separated by spaces.

 

Output
One line containing the lenght of the longest increasing subsequence in A.

 

Example
Input:
5
1 4 2 4 3
Output:
3
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


ll lengthOfLIS(const vector<ll>& v) {
    ll n = v.size();
    vector<ll> tail(1, 0);
    tail[0] = v[0];
    for (int i = 1; i < n; ++i) {
    	if(v[i] < tail[0]) {
    		tail[0] = v[i];
    	}
    	else if(v[i] > tail.back()) {
    		tail.push_back(v[i]);
    	}
    	else {
    		int index = lower_bound(tail.begin(), tail.end(), v[i]) - tail.begin() ; 
    		tail[index] = v[i];
    	}
    }

    return tail.size();
}

int main() {
	sync;
	int n ;
	cin >> n;
	vector < ll > v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	cout << lengthOfLIS(v) ;

	return 0;
}
