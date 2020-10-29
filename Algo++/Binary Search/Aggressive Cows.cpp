/*

Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,…,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?


Input Format:
First line contains N and C, separated by a single space, representing the total number of stalls and number of cows respectively. The next line contains N integers containing the indexes of stalls.

Output Format:
Print one integer: the largest minimum distance.

Sample Input:
5 3
1 2 8 4 9
Sample Output:
3
Explanation:
Problem Credits (Spoj)[http://www.spoj.com/problems/AGGRCOW/]


*/




#include <iostream>
#include <algorithm>
using namespace std;
bool isValidConfig(long long a[], long long n, long long m, long long c)
{
	c--;
	long long previous = a[0];
	for (long long i = 1; i < n && c; i++)
	{
		if (a[i] - previous >= m)
		{
			previous = a[i];
			c--;
		}
	}
	if (c == 0)
	{
		return true;
	}
	return false;
}
int main()
{
	long long a[100000], n, i,  c;
	cin >> n >> c;
	long long s, e, mid, ans;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	s = a[0];
	e = a[n - 1];
	ans = -1;
	while (s <= e)
	{
		mid = (s + e) / 2;
		if (isValidConfig(a, n, mid, c))
		{
			ans = mid;
			s = mid + 1;
		}
		else
			e = mid - 1;
	}
	cout << ans;
	return 0;
}
