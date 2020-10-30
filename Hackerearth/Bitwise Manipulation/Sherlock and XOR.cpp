/*  Sherlock and XOR
You are given an array A1,A2...AN. You have to tell how many pairs (i, j) exist such that 1 ≤ i < j ≤ N and Ai XOR Aj is odd.

Input and Output
First line T, the number of testcases. Each testcase: first line N, followed by N integers in next line. For each testcase, print the required answer in one line.

Constraints
1 <= T <= 10
1 <= N <= 10^5
0 <= Ai <= 10^9

SAMPLE INPUT
2
3
1 2 3
4
1 2 3 4
SAMPLE OUTPUT
2
4
*/





/*      The logic of this approach:

For a number to be odd, its last bit should be set. So, for the XOR of two numbers to be odd, their last bits should be 0&1 or 1&0, which implies that one of them is odd and the other is even. So all we need to look for is the number of distinct pairs of even and odd numbers. This number is (no. of odd nos)*(no. of even nos).

*/



#include <iostream>

using namespace std;

int main()
{
    long test, m, i, n, j;
    cin >> test;
    long odd, even;

    while (test--)
    {
        odd = 0;
        even = 0;
        cin >> n;

        for (i = 0; i < n; i++)
        {
            cin >> m;

            if (m & 1)
                odd++;
            else
                even++;
        }

        cout << (odd * even) << endl;
    }

    return 0;
}
