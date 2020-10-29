#include <iostream>
#include <ctime>
#include <cstdlib>
#define size 200005
using namespace std;
long long partition(long long *a,long long s,long long e)
{
    long long pivot = a[e];
    long long i = s-1;
    long long j = s;
    for( ; j<e;j++)
    {
        if(a[j] < pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }

    //Bring pivot element to its correct position
    swap(a[i+1],a[e]);
    return i+1;
}
void quicksort(long long *a,long long s,long long e)
{
    if(s>=e)
        return ;
    
    long long p = partition(a,s,e);
    quicksort(a,s,p-1);     //sort the left part i.e. part that is less than pivot element
    quicksort(a,p+1,e);     //sort the right part i.e. part that is greater than pivot element
}
void shuffle(long long *a,long long n)
{
    srand(time(0));
    for(long long i=n-1;i>0;i--)
    {
        long long j = rand()%(i+1);
        swap(a[i],a[j]);
    }
}
int main() 
{
    long long a[size];
    long long n ;
    cin>>n;
    for(long long i = 0; i < n; i++)
        cin>>a[i];

    shuffle(a,n);
    quicksort(a,0,n-1);

    for(long long i = 0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}

