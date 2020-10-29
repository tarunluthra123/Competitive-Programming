/*
SUBSET SUM EASY
Mike is a very passionate about sets. Lately, he is busy solving one of the problems on sets. He has to find whether if the sum of any of the non-empty subsets of the set A is zero.


Input Format:
The first line contains an integer T, which is the total number of test cases. T

test cases follow.

Each test case consists of two lines.

The first line consists of a single integer N, which is the number of elements

present in the set A.

The second line contains the integer in the set.

Constraints:
1 = T =10
1 = N = 4
-10^5 = A[i] = 10^5

Output Format:
If the sum of any of the subset is zero, then print “Yes” (without

quotes) else print “No”(without quotes).

Sample Input:
1
4
1 2 3 -3
Sample Output:
Yes
Explanation:
The sum of the subset {3,-3} is zero.
*/
#include <iostream>
using namespace std;
long generateSubset(long a[],int n)
{
    long ans = 0;
    int i = 0;
    while(n)
    {
        if(n&1)
            ans+=a[i];
        i++;
        n=n>>1;
    }
    return ans;
}
void subsetSumZero(long a[],int n)
{
    int limit = (1<<n);
    for(int i = 1;i < limit ; i++)
    {
        long temp = generateSubset(a,i);
        if(temp==0)
        {
            cout<<"Yes";
            return;
        }
    }
    cout<<"No";
}

bool subsetSumEasy(const vector<int> &v, int i = 0, int sum = 0, bool included = false)
{
    if (i == v.size())
    {
        return (sum == 0 && included);
    }

    bool inc = subsetSumEasy(v, i + 1, sum + v[i], true);
    bool exc = subsetSumEasy(v, i + 1, sum, included);

    return inc || exc;
}

int main() 
{
    int testCases;
    long a[5];
    cin>>testCases;
    while(testCases--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        subsetSumZero(a,n);
        cout<<endl;
    }
    
    return 0;
}

