#include <iostream>
using namespace std;
int partition(int *a,int s,int e)
{
    int pivot = a[e];
    int i = s-1;
    int j = s;
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
void quicksort(int *a,int s,int e)
{
    if(s>=e)
        return ;
    
    int p = partition(a,s,e);
    quicksort(a,s,p-1);     //sort the left part i.e. part that is less than pivot element
    quicksort(a,p+1,e);     //sort the right part i.e. part that is greater than pivot element
}
int main() 
{
    int a[] = {2,1,5,7,3,9,0,6,23,65,76,31,17};
    int n = sizeof(a)/sizeof(int);
    quicksort(a,0,n-1);
    for(int i = 0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}

