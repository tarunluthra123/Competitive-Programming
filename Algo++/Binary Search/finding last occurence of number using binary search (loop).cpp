//https://hack.codingblocks.com/contests/c/537/88
#include <iostream>
using namespace std;
typedef long long int ll;
int searchLast(ll a[],ll n,ll key)//,ll start,ll end)
{   int start=0,end=n-1;
    int ans=-1;
    while(start<=end)
    {
        int mid=(start+end)/2;

        if(a[mid]==key)
        {
            start=mid+1;
            ans=mid;
        }
        else if (a[mid]>key)
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return ans;

}
int main() 
{
    ll a[1000],n,key;
    cin>>n;
    for(ll i=0;i<n;i++)
        cin>>a[i];
    cin>>key;
    cout<<searchLast(a,n,key);
    return 0;
}

