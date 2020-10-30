/*
https://www.hackerearth.com/practice/algorithms/searching/linear-search/practice-problems/algorithm/subarrays-f2fc878d/


Subarrays

You are given an array s of length N . You are required to select K non-intersecting subarrays. The cost will be considered as the sum of all numbers in these subarrays divided by K. Your task is to maximize this cost.

A subarray of  is a non-empty sequence obtained by deleting a prefix and/or a suffix from the sequence . The prefix or suffix can be empty which means that  is considered to be a subarray of . There are subarrays in an array of length .

You can select no subarrays (K=0) and the cost is considered to be equal to 0. 

If there are more than one solutions that contain the same cost, then select the one that contains the highest K.

Input format

First line: Integer - N
Second line:  N integers of array s
Output format:

If the maximum cost is equal to  C, then print two integers floor(C) and K respectively.

Note: The value of floor(C) is equal to the biggest integer less than or equal to C.

Additional information

SAMPLE INPUT 
5
1 -5 3 -1 4
SAMPLE OUTPUT 
6 1
*/


#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define FOI(i, a, n) for( i = int(a); i <= int(n); i++)
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007

#define ll  long long int
#define pii pair<lli, lli>
#define vi  vector<ll>

istream& operator >>(istream& cin,vi &a) { ll i,n ; cin >> n ;  a.resize(n); FOI(i,0,n-1) { cin>>a[i];  } return cin ; }

int main() { 
    sync;
    ll n ;
    cin >> n;
    ll i;
    vi v(n);
    FOI(i, 0, n-1) {
        cin >> v[i];
    }

    ll cs = 0 ;
    ll ms = 0 ;
    vi arr(n);
    FOI(i, 0, n-1) {
        if(cs < 0) 
            cs = 0;
        cs += v[i];
        ms = max(ms,cs) ;
        arr[i] = cs;
    }

    ll k = 0;
    FOI(i, 0, n-1) {
        if(arr[i] == ms)
            k++;
    }
    
    cout << ms << " " << k;

    return 0;
}
