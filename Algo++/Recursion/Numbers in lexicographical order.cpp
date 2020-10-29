/*
RECURSION-LEXICOGRAPHICAL ORDER
Take as input N, a number. Write a recursive function which prints counting from 1 to N in lexicographical order. In lexicographical (dictionary) order 10, 100 and 109 will be printed before 11.


Input Format:
Enter a number N.

Constraints:
None

Output Format:
Display all the numbers upto N in a lexicographical order

Sample Input:
10
Sample Output:
0 1 10 2 3 4 5 6 7 8 9 
*/

#include <bits/stdc++.h>
using namespace std;

void helper(int curr, int n, vector<int> &ans)
{
    if (curr > n)
    {
        return;
    }

    ans.push_back(curr);

    for (int i = 0; i < 10; i++)
    {
        helper(10 * curr + i, n, ans);
    }
}

void printLexicographical(int n)
{
    vector<int> ans;
    for (int i = 1; i < 10; i++)
    {
        helper(i, n, ans);
    }

    for (int x : ans)
    {
        cout << x << " ";
    }
}

int main()
{
    int n;
    cin >> n;

    printLexicographical(n);

    return 0;
}
