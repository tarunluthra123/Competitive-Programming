/*
SORTED ARRAY
Take as input N, the size of an integer array. Take one more input, which is a list of N integers separated by a space, and store that in an array. Write a recursive function which prints true if the array is sorted, and false otherwise.


Input Format:
N x y z

Constraints:
1 < N < 1000

-10^9 < i < 10^9, where i is an element of the array

Output Format:
true OR false

Sample Input:
5
1 2 3 4 5
Sample Output:
true
*/
#include <iostream>
using namespace std;

bool isSorted(int *a,int i,int n){
    if(i == n-1){
        return true ;
    }
    if(a[i] > a[i+1]){
        return false ;
    }

    return isSorted(a,i+1,n);
}

int main() {
    int n ;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    cout << boolalpha << isSorted(a,0,n);

    return 0;
}

