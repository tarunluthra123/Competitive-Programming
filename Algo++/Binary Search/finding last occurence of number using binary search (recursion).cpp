#include <iostream>
using namespace std;
typedef long long int ll;
int searchLast(ll a[],ll n,ll key,ll start,ll end)
{   //int start=0,end=n-1;
    int ans=-1;
    if(start>end)
    return -1;
    int mid=(start+end)/2;
    if(a[mid]==key)
    {
       start=mid+1;
       ans=searchLast(a,n,key,start,end);
       if(ans==-1)
       return mid;
       else
       return ans;
    }
    else if (a[mid]>key)
    {
        end=mid-1;
        return searchLast(a,n,key,start,end);
    }
    else
    {
       start=mid+1;
       return searchLast(a,n,key,start,end);
    }
    
}
int main() 
{
    ll a[1000],n,key;
    cin>>n;
    for(ll i=0;i<n;i++)
        cin>>a[i];
    cin>>key;
    cout<<searchLast(a,n,key,0,n-1);
    return 0;
}

