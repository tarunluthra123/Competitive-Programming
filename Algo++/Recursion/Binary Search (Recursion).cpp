/* Program for using binary search (recursion) algorithm 
   Created by Tarun Luthra
   Roll No. = 2018 CSC 1023   																	*/
   
#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch(int arr[], int start, int end, int key)
{
	if (end>=start)
    {
		int mid =(end + start) / 2;

		if (arr[mid] == key)
			return mid;

		if (arr[mid] > key)
			return binarySearch(arr,start, mid-1, key);

		return binarySearch(arr, mid+1, end, key);
	}

	return -1;      //return -1 in case key not found
}

int main()
{
	int arr[1000];
    int n,i;
    cout<<"Enter size of array = ";
    cin>>n;
    cout<<"Enter "<<n<<" elements :";
    for(i=0;i<n;i++)
        cin>>arr[i];

    sort(arr,arr+n);        //binary search only works on sorted arrays

    cout<<"Your sorted array is ";
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\nEnter an element to search in the array = ";
    int key;
    cin>>key;
    cout<<endl;
    int ans = binarySearch(arr,0,n,key);
    if(ans == -1)
        cout<<"Key not found in the array";
    else
        cout<<"Key found at position = "<<ans+1;
	return 0;
}
