/*
https://www.spoj.com/problems/UPDATEIT/

UPDATEIT - Update the array !
You have an array containing n elements initially all 0. You need to do a number of update operations on it. In each update you specify l, r and val which are the starting index, ending index and value to be added. After each update, you add the 'val' to all elements from index l to r. After 'u' updates are over, there will be q queries each containing an index for which you have to print the element at that index.

Input
First line consists of t, the number of test cases. (1 <= t <= 10)

Each test case consists of "n u",number of elements in the array and the number of update operations, in the first line (1 <= n <= 10000 and 1 <= u <= 100000)

Then follow u lines each of the format "l r val" (0 <= l,r < n, 0 <= val <=10000)

Next line contains q, the number of queries. (1 <= q <= 10000)

Next q lines contain an index (0 <= index < n)

Output
For each test case, output the answers to the corresponding queries in separate lines.

Example
Input:
1
5 3
0 1 7
2 4 6
1 3 2
3
0
3
4

Output:
7
8
6
*/
#include <bits/stdc++.h>
using namespace std;

#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector<int> BIT;

void update(int i,int val) {
    int n = BIT.size();
    while(i <= n) {
        BIT[i] += val;
        i = i + (i & (-i));
    }
}

int query(int i) {
    int sum = 0;
    while(i > 0) {
        sum += BIT[i];
        i = i- (i &(-i));
    }
    return sum;
}

int main() {
    sync;
    int testCases;
    cin >> testCases;
    while (testCases--) {
        int n;
        cin >> n;
        BIT.resize(n+1,0);

        int u; //No of updates
        cin >> u;

        while(u--) {
            int l,r,val;
            cin >> l >> r >> val;
            
            l++; r++;
            update(l,val);
            update(r+1,-val);
        }

        int q;
        cin >> q;
        while(q--) {
            int index;
            cin >> index;
            index++;

            cout << (query(index)) << endl;
        }

        BIT.clear();
    }

    return 0;
}
