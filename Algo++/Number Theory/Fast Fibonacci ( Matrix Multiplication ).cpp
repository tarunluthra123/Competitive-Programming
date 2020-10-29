/*
FAST FIBONACCI

Fibonacci series is well-known series in which in which each number (Fibonacci number) is the sum of the two preceding numbers. The series looks like 1, 1, 2, 3, 5, 8…. and so on. Your task is to find nth number.
Since the number can be large, output the answer modulo (109+7).


Input Format:
An integer T, denoting the number of test cases. Each test case contains and integer N.

Constraints:
1<=T<=10^5
1<=N<=10^9

Output Format:
Print the nth Fibonacci number modulo (109+7).

Sample Input:
4
3
4
5
6
Sample Output:
2
3
5
8
*/
#include <bits/stdc++.h>
using namespace std;

#define ll  long long int
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define test ll testCases; cin >> testCases; while(testCases--)
#define MOD 1000000007

void multiply (ll F[2][2], ll M[2][2]) {
    ll x = ( F[0][0] * M[0][0] + F[0][1] * M[1][0] ) % MOD;
    ll y = ( F[0][0] * M[0][1] + F[0][1] * M[1][1] ) % MOD;
    ll z = ( F[1][0] * M[0][0] + F[1][1] * M[1][0] ) % MOD;
    ll w = ( F[1][0] * M[0][1] + F[1][1] * M[1][1] ) % MOD;

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void power(ll F[2][2], ll n) {
    if (n == 0 || n == 1)
        return;

    ll M[2][2] = {{1, 1}, {1, 0}};

    power (F, n / 2);
    multiply (F, F);

    if (n % 2 != 0)
        multiply (F, M);
}


/* function that returns nth Fibonacci number */
ll fib(ll n) {
    ll F[2][2] = {{1, 1}, {1, 0}};

    if (n == 0)
        return 0;

    power (F, n - 1);
    return F[0][0] % MOD;
}

int main() {
    sync ;
    test{
        ll n ;
        cin >> n;
        cout << fib(n) % MOD<< endl;
    }

    return 0;
}

