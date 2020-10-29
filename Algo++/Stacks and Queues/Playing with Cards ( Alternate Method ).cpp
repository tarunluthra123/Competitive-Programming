/*
/*
PLAYING WITH CARDS (IN STACK)
You are at a casino. There are N stacked cards on pile . Each card has a number written on it. Then there will be Q iterations. In ith iteration, you start picking up the cards in Ai-1th pile from the top one by one and check whether the number written on the card is divisible by the ith prime number. If the number is divisible, you stack that card on pile Bi. Otherwise, you stack that card on pile Ai. After Q iterations, cards can only be on pile B1, B2, B3, . . . BQ, AQ . Output numbers on these cards from top to bottom of each piles in order of B1, B2, B3, . . . BQ, AQ .


Input Format:
First line contains N and Q. The next line contains N space separated integers representing the initial pile of cards i.e., A0. The leftmost value represents the bottom plate of the pile.

Constraints:
N < 10^5

Output Format:
Output N lines, each line containing the number written on the card.

Sample Input:
5 1
3 4 7 6 5
Sample Output:
4
6
3
7
5
Explanation:
Initially:

A0 = [3, 4, 7, 6, 5]<-TOP

After 1st iteration:

A0 = []<-TOP

A1 = [5, 7, 3]<-TOP

B1 = [6, 4]<-TOP

Now first print B1 from top to bottom then A1 from top to bottom.
*/

*/
#include<bits/stdc++.h>
#define lli long long int
using namespace std;
void sieve(vector<lli> &v)
{
	vector<bool> prime(40,true);
	prime[0]=false;
	prime[1]=false;
	for(lli i=2;i<=40;i++)
	{
		if(prime[i]==true)
		{
			for(lli j=i+i;j<=167;j=j+i)
			{
				prime[j]=false;
			}
			v.push_back(i);
		}
	}
}
int main()
{
	stack<lli> s;
	lli n,q,d,x,i;
	lli y;
	vector<lli> v;
	sieve(v);
	cin>>n>>q;
    while(n--)
    {
        cin>>d;
        s.push(d);
    }
    stack<lli> a;
    stack<lli> b;
    queue<lli> q;
    for(i=1;i<=q;i++)
    {
    	while(!s.empty())
    	{
    		x=s.top();
            y=v[i-1];
    		if(x%y==0)
    		{
    			b.push(x);
			}
			else
			{
				a.push(x);
			}
            s.pop();
		}
        while(!b.empty())
        {
            x=b.top();
            q.push(x);
            b.pop();
        }
        swap(s,a);
	}
	while(!q.empty())
	{
		cout<<q.front()<<endl;
		q.pop();
	}
	while(!s.empty())
	{
		cout<<s.top()<<endl;
		s.pop();
	}
	return 0;
}
