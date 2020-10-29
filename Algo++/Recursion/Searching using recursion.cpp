#include <iostream>
#include <algorithm>
using namespace std;
int linearSearch(int *a,int index,int n,int key)
{
    if(index>=n)
        return -1;
    if(a[index]==key)
        return index;
    
    return linearSearch(a,index+1,n,key);
}

int binarySearch(int *a,int start,int end,int key)
{
    if(start>end)
        return -1;

    int mid = (start+end)/2;
    if(a[mid]==key)
        return mid;
    
    if(a[mid]<key)
        return binarySearch(a,mid+1,end,key);
    
    
    return binarySearch(a,start,mid-1,key);
}
int main() 
{
    int a[] = {1,2,3,5,6,8,10};
    int n = sizeof(a)/sizeof(int);
    int x = 6;
    cout<<linearSearch(a,0,n,x)<<endl;
    cout<<binarySearch(a,0,n,x);
    return 0;
}
