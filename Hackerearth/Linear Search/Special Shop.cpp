/*
https://www.hackerearth.com/practice/algorithms/searching/linear-search/practice-problems/algorithm/special-shop-69904c91/

Special Shop
Creatnx now wants to decorate his house by flower pots. He plans to buy exactly N ones. He can only buy them from Triracle's shop. 
There are only two kind of flower pots available in that shop. The shop is very strange. If you buy X flower pots of kind 1 then you must pay A*X*X and B*Y*Y
 if you buy Y flower pots of kind 2. Please help Creatnx buys exactly N flower pots that minimizes money he pays.

Input Format

The first line contains a integer T  denoting the number of test cases.

Each of test case is described in a single line containing three space-separated integers - N,A,B

Output Format

For each test case, print a single line containing the answer.

Constraints
1 < t < 10^5
1 < N,A,B < 10^5 

SAMPLE INPUT 
2
5 1 2
10 2 4

SAMPLE OUTPUT 
17
134

*/
#include <bits/stdc++.h>
using namespace std;

#define FOI(i, a, n) for( i = int(a); i <= int(n); i++)
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define ll  long long int
#define ld long double

int main() { 
    sync;
    int testCases;
    cin >> testCases;
    while (testCases--) {
        ll n,a,b;
        cin >> n >> a >> b;
        
        ld x = (ld)(b*n)/(ld)(a+b);     //Using formula derived by calculating minima for the given cost function
        //cout << "x = " << x << endl;

        if(x >= ceil(x)-0.5) {
            x = (ll)(ceil(x));
        }
        else {
            x = (ll)(floor(x));
        }
        //cout << "x = " << x << endl;

        ll ans = a*x*x + b*(n-x)*(n-x);

        cout << ans << endl;
    }
    return 0;
}
