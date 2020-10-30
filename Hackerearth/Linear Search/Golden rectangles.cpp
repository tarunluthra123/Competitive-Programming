/*
https://www.hackerearth.com/practice/algorithms/searching/linear-search/practice-problems/algorithm/almost-golden-rectangular-1c9d72c0/

Golden rectangles
You have N rectangles. A rectangle is golden if the ratio of its sides is in between 1.6-1.7, both inclusive. Your task is to find the number of golden rectangles.

Input format

First line: Integer  denoting the number of rectangles N
Each of the N  following lines: Two integers  denoting the width W and height H of a rectangle
Output format

Print the answer in a single line.
Constraints
1<=N<=10^5
1<=W,H<=10^9


SAMPLE INPUT 
5
10 1
165 100
180 100
170 100
160 100

SAMPLE OUTPUT 
3
Explanation
There are three golden rectangles: (165, 100), (170, 100), (160, 100).
*/
#include <bits/stdc++.h>
using namespace std;

#define FOI(i, a, n) for( i = int(a); i <= int(n); i++)
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define ll  long long int
#define ld long double

int main() { 
    sync;
    ll c = 0;
    int n;
    cin >> n;
    while (n--) {
        double w,h;
        cin >> w >> h;
        double ratio = w/h;
        if(ratio>=1.6 && ratio <=1.7) {
            c++;
        }
        ratio = h/w;
        if(ratio>=1.6 && ratio <=1.7) {
            c++;
        }
    }

    cout << c;

    return 0;
}
