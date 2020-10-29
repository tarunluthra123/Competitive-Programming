/*
MAXIMUM LENGTH BIOTONIC SUBARRAY
You are provided n numbers of array. You need to find the maximum length of bitonic subarray. A subarray A[i … j] is biotonic if there is a k with i <= k <= j such that A[i] <= A[i + 1] … <= A[k] >= A[k + 1] >= .. A[j – 1] > = A[j] i.e subarray is first increasing and then decreasing or entirely increasing or decreasing.


Input Format:
First line contains integer t which is number of test case. For each test case, it contains an integer n which is the size of array and next line contains n space separated integers.

Constraints:
1<=t<=100
1<=n<=1000000

Output Format:
Print the maximum length.

Sample Input:
2
6
12 4 78 90 45 23
4
40 30 20 10
Sample Output:
5
4
Explanation:
ForMaximum length = 4, 78, 90, 45, 23
*/
#include <iostream>
#include <vector>
using namespace std;

int maxBiotonicSubarray(vector<int> v){
    int n = v.size();
    int inc[n] = {0};
    int dec[n] = {0};
    

    inc[0] = 1;
    dec[n-1] = 1;

    for(int i=1;i<n;i++){
        if(v[i] >= v[i-1]){
            inc[i] = inc[i-1] + 1;
        }
        else {
            inc[i] = 1;
        }
    }

    for(int i=n-2;i>=0;i--){
        if(v[i] >= v[i+1]){
            dec[i] = dec[i+1] + 1;
        }
        else {
            dec[i] = 1;
        }
    }

    /*
    cout << "Inc - ";
    for(int i=0;i<n;i++){
        cout << inc[i] << " ";
    }
    cout <<"\nDec - ";
    for(int i=0;i<n;i++){
        cout << dec[i] << " ";
    }
    cout << endl; 
    */

    int maxLength = 0 ;
    for(int i=0;i<n;i++){
        int currentLength = inc[i] + dec[i] - 1 ;
        maxLength = max(maxLength,currentLength);
    }

    return maxLength ;
}


int main() {
    int testCases;
    cin >> testCases;
    while(testCases--){
        int n ;
        cin >> n;
        vector<int> v;
        for(int i=0;i<n;i++){
            int temp;
            cin >> temp;
            v.push_back(temp);
        }

        cout << maxBiotonicSubarray(v) << endl;
    }
    
    
    
    return 0;
}

