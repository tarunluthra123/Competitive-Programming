/*
MAXIMUM LENGTH BIOTONIC SUBSEQUENCE
You are provided n numbers of array. You need to find the maximum length of bitonic subsequence. An subsequence is bitonic if it is first increasing and then decreasing or entirely increasing or decreasing.


Input Format:
First line contains integer t which is number of test case. For each test case, it contains an integer n which is the size of array and next line contains n space separated integers.

Constraints:
1<=t<=100
1<=n<=1000

Output Format:
Print the maximum length.

Sample Input:
2
8
1 11 2 10 4 5 2 1
6
80 60 30 40 20 10
Sample Output:
6
5
Explanation:
For 1st test case : Maximum length = 1, 2, 4, 5, 2, 1 For 2nd test case : Maximum length = 80, 60, 40, 20 10 or 80, 60, 30, 20 10
*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int maxBiotonicSubsequence(vector<int> a){
    int n = a.size();
    int inc[n] ;
    int dec[n] ;
    
    memset(inc,0,sizeof(inc));
    memset(dec,0,sizeof(dec));
    inc[0] = 1;
    dec[n-1] = 1;

    //int maxIncLength = -1;

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j] <= a[i]){
                int currentLength = 1 + inc[j];
                inc[i] = max(currentLength,inc[i]);
            }
        }
        if(inc[i] == 0){
            inc[i] = 1;
        }
        //maxIncLength = max(maxIncLength,inc[i]);
    }


    //int maxDecLength = -1;

    for(int i=n-2;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(a[j] <= a[i]){
                int currentLength = 1 + dec[j];
                dec[i] = max(currentLength,dec[i]);
            }
        }
        if(dec[i] == 0){
            dec[i] = 1;
        }
        //maxDecLength = max(maxDecLength,dec[i]);
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

        cout << maxBiotonicSubsequence(v) << endl;
    }
    
    
    
    return 0;
}

