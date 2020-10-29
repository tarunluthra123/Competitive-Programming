/*
MAXIMUM POWER
Alice is fighting with an alien to save this planet. As alien is very powerful he needs some power to overcome him. Power points are represented in the form of an array containing both positive and negative powers but the problem is he can get power equal to the product of the subarray he selects. Help him to decide maximum power he can get.


Input Format:
First line contains an integral value denoting the size of array 'n' and then next line represents the array elements.

Constraints:
1<=n<=100000
Product of all numbers will fit in long long int.

Output Format:
Single integer denoting the maximum power.

Sample Input:
8
10 1 2 -13 0 7 -18 2 
Sample Output:
20
Time Limit: 1 sec
*/
#include <bits/stdc++.h> 
using namespace std; 
#define lli long long int


// Function to find maximum product subarray 
lli maxProduct(lli *arr, int n) { 
	lli minVal = arr[0]; 
	lli maxVal = arr[0]; 

	lli maxProduct = arr[0];    //Final answer variable

	for (int i = 1; i < n; i++) { 

		// When multiplied by -ve number , products become opposite
		if (arr[i] < 0) {
			swap(maxVal, minVal); 
        }

		// maxVal and minVal stores the product of subarray ending at arr[i]. 
		maxVal = max(arr[i], maxVal * arr[i]); 
		minVal = min(arr[i], minVal * arr[i]); 

		// Max Product of array. 
		maxProduct = max(maxProduct, maxVal); 
	} 

	return maxProduct; 
} 

int main() { 
	int n ;
    cin >> n;
    lli a[n];
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }

	cout << maxProduct(a, n) << endl; 

	return 0; 
} 

