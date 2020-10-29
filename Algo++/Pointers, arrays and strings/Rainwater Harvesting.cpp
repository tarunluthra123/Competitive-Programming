/*
RAIN WATER HARVESTING
Apoorvaa has created an elevated roof. She wants to know how much water can she save during rain.

Given n non negative integers representing the elevation map where width of every bar is 1, Find the maximum water that she can save.

Explanation for the Sample input Testcase:
Elevation Map

So the total units of water she can save is 5 units


Input Format:
First line contains an integer n. Second line contains n space separated integers representing the elevation map.

Output Format:
Print a single integer containing the maximum unit of waters she can save.

Sample Input:
10
0 2 1 3 0 1 2 1 2 1
Sample Output:
5
Time Limit: 1 sec
*/

#include <iostream>
using namespace std;
int main() 
{
    int a[10000],left[10000],right[10000],n,i,j;
    cin>>n;
    for(i=0;i<n;i++)
    {   cin>>a[i];  }
    left[0]=a[0];  right[n-1]=a[n-1];
    int leftmax=0,rightmax=0;
    for(i=1;i<n;i++)
    {
        //if(a[i]>leftmax)
        //leftmax=a[i];
        //left[i]=leftmax;
        left[i] = max(left[i-1],a[i]);
    }
    for(i=n-2;i>=0;i--)
    {
       // if(a[i]>rightmax)
      //  rightmax=a[i];
      //  right[i]=rightmax;
        right[i] = max(right[i+1], a[i]); 
    }
    int water=0;
    for(i=0;i<n;i++)
    {
        water+=(min(left[i],right[i])-a[i]);
    }
    cout<<water;

    return 0;
}
