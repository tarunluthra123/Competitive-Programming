/*
https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/chinu-and-his-project/

Xor and project
A project was going on related to image processing and to perform experiments and get desired result the image needs to be converted to Gray-Scale using a parameter 'x' and the function P(x) represented the Gray-Code and calculated via x xor (x div 2) where xor stands for bitwise exclusive OR (bitwise modulo 2 addition), and div means integer division.

It is interesting to note that function P(x) is invertible, which means it is always possible to uniquely restore x given the value of P(x).

So the group working on the project forgot to keep the original data related to parameter 'x'. Write a program to restore number x from the given value of P(x).

INPUT:
The input file contains an integer number y, the value of G(x).

OUTPUT:
The output file should contain a single integer x such that G(x) = y.

CONSTRAINTS:
0 ≤ x,P(x) ≤ 10^9 .

SAMPLE INPUT
15
SAMPLE OUTPUT
10
*/

#include<iostream>
using namespace std;
int main()
{
    long long int n, x = 0;
    cin >> n;

    while (n > 0)
    {
        x = x ^ n;
        n = n / 2;
    }

    cout << x << endl;
    return 0;
}
