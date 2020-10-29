/*
COUNT NUMBER OF BINARY STRINGS
You are provided an integers N. You need to count all possible distinct binary strings of length N such that there are no consecutive 1’s.


Input Format:
First line contains integer t which is number of test case. For each test case, it contains an integer n which is the the length of Binary String.

Constraints:
1<=t<=100
1<=n<=90

Output Format:
Print the number of all possible binary strings.

Sample Input:
2
2
3
Sample Output:
3
5
Explanation:
1st test case : 00, 01, 10 2nd test case : 000, 001, 010, 100, 101
*/
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

ull fib[100];
void createFibonnaci(){
    fib[0] = 1;
    fib[1] = 2;
    fib[2] = 3;
    fib[3] = 5;
    for(int i=4;i<=100;i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
}

int main() {
    createFibonnaci() ; 
    int testCases;
    cin >> testCases;
    while(testCases--){
        
        int n ;
        cin >> n;
        for(int i=0;i<n+1;i++){
            dp[i] = 0 ;
        }
        cout << fib[n] << endl;
    }



    return 0;
}

