/*
Mr.X firm

Mr. X is starting a firm in which he hired N number of workers. Mr.X need to divide all the workers in K groups such that each group has atleast one worker. Each pair of workers from a group become friends.

Now to increase the productivity, Mr. X wants to divide them in K groups such that minimum number of pair of friends are possible after dividing them into groups. Your task is to print the minimum number of possible pairs.

Input Format
The input contains two integers N and K (The Number of Workers and the required groups respectively).

Constraints
1?=?K?=?N?=?10^9

Output Format
The output line only contains an integer Y (the minimum number of pairs possible).

Sample Input
10 3
Sample Output
12
*/

#include <iostream>
using namespace std;
#define ll long long int

int main() {
    ll n,k;
    cin >> n >> k;
    ll x = n/k;
    ll r = n%k;

    ll ans = (x*(x-1)/2)*(k-r) + (x*(x+1)/2)*r;

    cout << ans;
    return 0;
}

