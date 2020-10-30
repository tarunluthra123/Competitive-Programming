/*
BUSYMAN - I AM VERY BUSY
#greedy
I AM VERY BUSY
You are actually very busy man. You have a big schedule of activities. Your aim is to do as much as activities as possible.



In the given figure, if you go to date with crush, you cannot participate in the coding contest and you can’t watch the movie. Also if you play DotA, you can’t study for the exam. If you study for the exam you can’t sleep peacefully. The maximum number of activities that you can do for this schedule is 3. 

Either you can

watch movie, play DotA and sleep peacefully (or)
date with crush, play DotA and sleep peacefully
Input Specifications
The first line consists of an integer T, the number of test cases. For each test case the first line consists of an integer N, the number of activities. Then the next N lines contains two integers m and n, the start and end time of each activity.

Output Specifications
For each test case find the maximum number of activities that you can do.

Input Constraints
1 <= T <=10
1 <= N <= 100000
0 <= start < end <= 1000000

Example
Sample Input: (empty lines just for clarity)
3
3
3 9
2 8
6 9

4
1 7
5 8
7 8
1 8

6
7 9
0 10
4 5
8 9
4 10
5 7

Sample Output:
1
2
3
*/
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define ff first
#define ss second
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

bool myCompare(pii a, pii b)
{
    return a.ss < b.ss;
}

int main()
{
    sync;
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        int n;
        cin >> n;
        vector<pii> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i].ff >> v[i].ss;
        }

        sort(v.begin(), v.end(), myCompare);

        pii current = v[0];
        int c = 1;
        for (int i = 1; i < n; i++)
        {
            if (v[i].ff >= current.ss)
            {
                c++;
                current = v[i];
            }
        }

        cout << c << endl;
    }

    return 0;
}
