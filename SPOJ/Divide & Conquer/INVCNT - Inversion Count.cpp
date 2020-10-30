/*
https://www.spoj.com/problems/INVCNT/

INVCNT - Inversion Count
Let A[0...n - 1] be an array of n distinct positive integers. If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A. Given n and an array A your task is to find the number of inversions of A.

Input
The first line contains t, the number of testcases followed by a blank space. Each of the t tests start with a number n (n <= 200000). Then n + 1 lines follow. In the ith line a number A[i - 1] is given (A[i - 1] <= 10^7). The (n + 1)th line is a blank space.

Output
For every test output one line giving the number of inversions of A.

Example
Input:
2

3
3
1
2

5
2
3
8
6
1


Output:
2
5
*/
#include <iostream>
#include <vector>
using namespace std;

#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int

// void print(ll a[], int start, int end) {
//     for (int i = start; i <= end; ++i) {
//         cout << a[i] << " " ;
//     }
//     cout << endl;
// }

ll merge(vector<ll> &a, int start, int end) {
    if(start > end) {
        return 0;
    }

    int mid = (start+end)/2;

    ll count = 0;

    int i = start;
    int j = mid + 1;
    int k = 0 ;

    vector<ll> temp(end-start+1,0);

    while(i <= mid && j <= end) {
        if(a[i] < a[j]) {
            temp[k++] = a[i++];
        }
        else {
            temp[k++] = a[j++];
            count += (mid - i + 1);
        }
    }

    while(i <= mid) {
        temp[k++] = a[i++];
    }

    while(j <= end) {
        temp[k++] = a[j++];
        count += (mid - i + 1);
    }

    j = 0;
    for (i = start; i <= end; ++i) {
        a[i] = temp[j++];
    }

    return count;
}

ll inversionCount(vector<ll> &a, int start, int end) {
    if(start >= end) {
        return 0;
    }

    ll ans = 0;

    int mid = (start+end)/2;

    ans += inversionCount(a, start, mid);
    ans += inversionCount(a, mid+1, end);

    //CROSS
    ans += merge(a, start, end);

    // cout << "s = " << start << "   e = " << end << "    ans = " << ans << endl;
    // print(a,start,end);

    return ans;
}

int main() { 
    sync;
    int testCases;
    cin >> testCases;
    while (testCases--) {
        int n;
        cin >> n;

        // ll a[200005];
        vector<ll> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        cout << inversionCount(a, 0, n-1) << endl;
    }

    return 0;
}
