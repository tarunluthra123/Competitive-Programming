#include <iostream>
using namespace std;
#define size 200005
void merge(long long *a,long long s,long long e)
{
    long long mid = (s+e)/2;
    long long i = s;
    long long j = mid + 1;
    long long k = s;
    long long temp[size] ;
    while(i<=mid && j<=e )
    {
        if(a[i]<a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while(i<=mid)
    {   temp[k++] = a[i++];     }
    while(j<=e)
    {    temp[k++] = a[j++];    }

    //Copy all elements of temp back into original array 'a'
    for(i=s;i<=e;i++)
        a[i] = temp[i];

}

void mergeSort(long long *a,long long s,long long e)
{
    //Base case
    if(s>=e)
        return ;

    //1. Divide
    long long mid = (s+e)/2;

    //2. Sort
    mergeSort(a,s,mid);
    mergeSort(a,mid+1,e);

    //3. Merge
    merge(a,s,e);
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long a[size];
    long long n ;
    cin>>n;
    for(long long i=0;i<n;i++)
        cin>>a[i];
    mergeSort(a,0,n-1);
    for(long long i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}

