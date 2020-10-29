/*
XOR PROFIT PROBLEM
We are given two coins of value x and y. We have to find the maximum of value of a XOR b where x <= a <= b <= y.

Input Format:
We are given two integers x and y

Constraints:
l <= r <= 1000

Output Format
Print the maximum value of a XOR b

Sample Input
5
6
Sample Output
3

Explanation:
If a and b are taken to be 5. Then a xor b = 0
If a and b are taken to be 6. Then a xor b = 0
If a is 5 and b is 6. Then a xor b is 3.

Time Limit: 1 sec
*/

#include <iostream>
 using namespace std;
 int main() 
 {
	 int x,y,ans=0,i,j;
	 cin>>x>>y;
	 for(i=x;i<=y;i++)
	 {
		 for(j=i;j<=y;j++)
		 {
		 	ans=max(ans,i^j);
		 }
	 }
 	cout<<ans;
 	return 0;
 }

