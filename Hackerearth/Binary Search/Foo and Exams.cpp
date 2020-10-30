/*
https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/foo-and-exams-4/

Foo and Exams
Foo was not amongst the most brilliant students of his class. So, he has some pending exams to clear. As the exams are approaching, this time he vowed to pass in all of them. This will only happen if he is not under stress. Foo's stress can be calculated using a simple function called Foo_function which depends upon the time for which Foo studies continuously .

Foo_funtion is defined as follows:

F(t)=A(t^3)+B(t^2)+C*(t)+D, F(t)<=10^18

where A,B,C,D belong to the set of prime numbers. t is the time in minutes for which foo studies continuously.

As foo is not very good at solving cubic equations, he seeks your help to find out the maximum number of minutes for which he can study continuously without taking stress. Help him find t such that F(t+1) > K, and F(t) <= K, where K is the maximum stress Foo can bear.

Input:

The first line of the input contains a single integer T denoting the number of test cases. each test case consists of a single line containing 5 space seperated positive numbers a, b, c, d, K.

Output:

for each test case, output a single integer t denoting the maximum time for which foo can study continuously without taking stress.

Constraints:

1 <= T <= 10^4 
A, B, C, D belong to a set of prime numbers such that F(t) would never exceed 10^18
t >= 0 
1 <= K <= 10^18

SAMPLE INPUT 
2
2 2 2 2 10
2 3 5 7 1000
SAMPLE OUTPUT 
1
7
Explanation
In the 1st test case for t = 2 foo will be under stress because F(2)=30 > K, therefore he can study for a maximum time of 1 minute without having stress.

In the 2nd test case for t = 8 foo will be under stess because F(8)=1263 > K, therefore he can study for a maximum time of 7 minutes continuously without having stress.
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


ll a,b,c,d;
ll f(ll t) {
    return a*t*t*t + b*t*t + c*t + d;
}

ll minStudyTime(ll k) {
    ll s = 0;
    ll e = 1000000;
    ll ans = 0;
    while(s<=e) {
        ll mid = (s+e)/2;
        //cout << "t = " << mid << "      f(t) = " << f(mid) << '\n';
        if(f(mid) < 0) {
        	//To control overflow condition
            e = mid - 1;
        }
        else if(f(mid) < k) {
            ans = mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    return ans;
}

int main() { 
    sync;
    int testCases;
    cin >> testCases;
    while (testCases--) {
        ll k;
        cin >> a >> b >> c >> d >> k;
        cout << minStudyTime(k) << endl;
    }


    return 0;
}
