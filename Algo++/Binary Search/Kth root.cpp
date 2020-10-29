/*
KTH ROOT
You are given two integers n and k. Find the greatest integer x, such that, x^k <= n.

Input Format:
First line contains number of test cases, T. Next T lines contains integers, n and k.

Constraints:
1<=T<=10 1<=N<=10^15 1<=K<=10^4

Output Format
Output the integer x

Sample Input
2
10000 1
1000000000000000 10
Sample Output
10000
31
*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	unsigned long long n, k, val, s, e, mid, finalAns;
	int testCases;
	cin >> testCases;
	while (testCases--)
	{
		if (k == 1)
		{
			cout << n << endl;	continue;
		}
		cin >> n >> k;
		s = 0;	 e = n / k;
		
		while (s <= e)
		{
			mid = (s + e) / 2;
			val = pow(mid, k);
			if (val == n)
			{
				finalAns = mid;
				break;
			}
			else if (val < n)
			{
				finalAns = mid;
				s = mid + 1;
			}
			else
				e = mid - 1;
		}
		cout << finalAns << endl;
		
	}
	return 0;
}
