/*
Monk's wizard friend Harry Potter is excited to see his Dad fight Dementors and rescue him and his Godfather Sirius Black. Meanwhile their friend Hermoine is stuck on some silly arrays problem. Harry does not have time for all this, so he asked Monk to solve that problem for Hermoine, so that they can go.

The problem is given an array A having N integers, for each i(1≤i≤N), find x+y,
where x is the largest number less than i such that A[x]>A[i] and y is the smallest number greater than i such that A[y]>A[i].
If there is no x<i such that A[x]>A[i], then take x=−1. Similarly, if there is no y>i such that A[y]>A[i], then take y=-1.
*/

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long int *a = new long int[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    stack<int> s;
    int *x = new int[n];
    int *y = new int[n];
    s.push (n - 1);

    for (int prev = n - 2; prev >= 0; prev--)
    {
        while (!s.empty() )
        {
            if (a[s.top()] < a[prev])
            {
                int index = s.top();
                x[index] = prev + 1; //Position is 1-indexing
                s.pop();
            }
            else
                break;
        }

        s.push (prev);
    }

    while (!s.empty() )
    {
        int index = s.top();
        x[index] = -1;
        s.pop();
    }

    s.push (0);

    for (int next = 1; next <= n - 1; next++)
    {
        while (!s.empty() )
        {
            if (a[s.top()] < a[next])
            {
                int index = s.top();
                y[index] = next + 1; //Position is 1-indexing
                s.pop();
            }
            else
                break;
        }

        s.push (next);
    }

    while (!s.empty() )
    {
        int index = s.top();
        y[index] = -1;
        s.pop();
    }

    for (int i = 0; i < n; i++)
    {
        cout << x[i] + y[i] << " ";
    }
}
