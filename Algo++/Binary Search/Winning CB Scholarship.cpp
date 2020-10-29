/*
WINNING CB SCHOLARSHIP
Prateek Bhaiya decided to give 100% scholarships to the needy students by taking an admission test. However in order to avoid any losses at the institute, he came up with a solution. Coding Blocks has N students and M discount coupons. A student will get 100% waiver if he gets X discount coupons. 
However in order to get more discount coupons in addition to those M , Bhaiya decided that some students who perform badly in the admission tests, need to pay additional amount equivalent to Y discount coupons, i.e. good students earn discount coupons and weak students need to pay coupons to get admission. 
Find out the maximum number of students who can get 100% waiver in their admission fees. 
Note : Bhaiya will try his best to give 100% discount to maximum students possible.

Input Format:
The first line contains 4 integers N M X Y

Constraints:
1 = N,M,X,Y = 10^9 ??

Output Format
The output should contain a single integer representing the maximum number of students who can get 100% discount.

Sample Input
5 10 2 1
Sample Output
5
*/

#include <iostream>
using namespace std;
bool isValidConfig(long good,long total,long m,long x,long y)
{
    long bad=total-good;
    long extra=bad*y;
    long temp=(m+extra)/x;
    if(temp>=good)
    return true;
    return false;
}
int main() 
{   
    long n,x,m,y;
    cin>>n>>m>>x>>y;
    long s=0,e=n,mid;
    long ans=-1;
    while(s<=e)
    {
        mid=(s+e)/2;
        if(isValidConfig(mid,n,m,x,y))
        {
            ans=mid;    s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }
    cout<<ans;




    return 0;
}
