//Bubble sort recursive

#include <iostream>
using namespace std;
void bubbleSort(int *a,int i,int n)
{
    //Base case
    if(n==1)
        return;
    
    if(i==n-1)
        return bubbleSort(a,0,n-1);

    if(a[i]>a[i+1])
        swap(a[i],a[i+1]);

    bubbleSort(a,i+1,n);
    return;
}
int main() {
    int a[] = {5,3,6,2,1,8};
    int n = 6;
    bubbleSort(a,0,n);
    for(int i =0;i<n;i++)
        cout<<a[i]<<" ";

    return 0;
}
