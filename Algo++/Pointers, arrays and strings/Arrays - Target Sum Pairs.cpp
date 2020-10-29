/*
ARRAYS-TARGET SUM PAIRS
Take as input N, the size of array. Take N more inputs and store that in an array. Take as input “target”, a number. Write a function which prints all pairs of numbers which sum to target.


Constraints:
Length of the arrays should be between 1 and 1000.
Sample Input:
5
1
3
4
2
5
5
Sample Output:
1 and 4
2 and 3
*/

#include <iostream>
#include <algorithm>
using namespace std;
int main() 
{
    int n,i,a[1000];
    cin>>n;
    int j;
    for(i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    int target;
    cin>>target;
    for(i=0;i<n;i++)
    {   
        for(j=i+1;j<n;j++)
        if(a[i]+a[j]==target)
        cout<<a[i]<<" and "<<a[j]<<endl;
    }
    return 0;
}

