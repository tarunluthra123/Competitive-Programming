/*
https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/chakra-numbers-9c9e0faf/


Special Bit Numbers


A number is known as special bit number if its binary representation contains atleast two consecutive 1's or set bits. For example 7 with binary representation 111 is a special bit number. Similarly 3(11) is also a special bit number as it contains atleast two consecutive set bits or ones.

Now the problem is, You are given an Array of N integers and Q queries. Each query is defined by two integers L, R. You have to output the count of special bit numbers in the range L to R.

Input

Contains integer N, no of Array elements and Q - Total Number of Queries.

Next line contains N integers A[i] defining Array elements.

Next Q lines contains Queries of the type
1<=L<=R<=N

Output

Output  Q lines containing answer for the ith Query.

Constraints

0<=[i]<=10^9
1<=N<=10^5

1<=Q<=10^5

SAMPLE INPUT
5 3
3 5 1 12 7
1 3
2 3
1 5
SAMPLE OUTPUT
1
0
3

Explanation
In Query 1 range is [1,3] and there is only one number with consecutive set bits is 3; So ans is 1.

In Query 2 range is [2,3] and there is no number is there with consecutive set bits. So ans is 0.

In Query 3 range is [1,5] and there are 3 numbers with consecutive bits set i.e 3, 12 and 7.

*/



#include <iostream>
using namespace std;
int isSpecialBitNumber (long n)
{
    int count = 0;

    while (n)
    {
        if (n & 1)
        {
            if (count == 0)
                count = 1;
            else if (count == 1)
                return 1;
        }
        else
            count = 0;

        n = n >> 1;
    }

    return 0;
}
int main()
{
    long n, q, l, r, i = 0;
    pair<long, int> a[100000];
    cin >> n;
    cin >> q;
    cin >> a[0].first;
    a[0].second = isSpecialBitNumber (a[i].first);

    for (i = 1; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = a[i - 1].second + isSpecialBitNumber (a[i].first);
    }

    cout << endl;
    int c = 0;

    while (q--)
    {
        c = 0;
        cin >> l >> r;

        if (l >= 2)
            c = a[r - 1].second - a[l - 2].second;
        else
            c = a[r - 1].second;

        cout << c << endl;
    }

    return 0;
}
