/*  
https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/a-new-experiment/

Help your roommate
After performing a lot of experiments at the SEGP and EEDC Lab, you need a break. You see your roommate stuck at a math problem. He asks for your help and says he will give you party at the NC if you solve this problem for him.

The problem is:

Initially you are given the number 0. After each day the numberdoubles itself. At any day, you can add the number 1 any number of times during the day.

You are given a number N and you need to tell the minimum number of times you have to add 1 to get N at any point of time.

Since you are very hungry, solve this problem for him to get something to eat for free.

Input Format:

The first line contains a single integer T denoting the number of test cases.
Next T lines contain the integer N.
Output Format:

For every test case print the required output.

Constraints:

1<=T<=100

1<= N<=10^9


SAMPLE INPUT
4
4
8
7
5
SAMPLE OUTPUT
1
1
3
2
*/

#include <iostream>
using namespace std;
unsigned long long countSetBits (unsigned long long n)
{
    unsigned long long ans = 0;

    while (n)
    {
        ans++;
        n = (n & (n - 1) );
    }

    return ans;
}

int main()
{
    unsigned long long test, n;
    cin >> test;

    while (test--)
    {
        cin >> n;
        cout << countSetBits (n) << endl;
    }

    return 0;
}
