/*
UGLY NUMBERS
You are provided a sequence of number. All numbers of that sequence is in increasing order (including 1) and whose only prime factors are 2, 3 or 5 (except 1). You need to find the nth number of that sequence.


Input Format:
First line contains integer t which is number of test case. For each test case, it contains an integer n.

Constraints:
1<=t<=100
1<=n<=10000

Output Format:
Print nth number of that sequence.

Sample Input:
2
7
10
Sample Output:
8
12
Explanation:
Sequence : 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, …..
*/

#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back

vector<lli> dp;

void generateUglyNumbers(){
    dp.pb(0);   //Marking 0 as 0th ugly number
    dp.pb(1);   //Marking 1 as 1st ugly number
    int i2 = 1;
    int i3 = 1;
    int i5 = 1;
    int j = 2;      //Loop counter variable
    lli nextMultipleOf2 = 2;
    lli nextMultipleOf3 = 3;
    lli nextMultipleOf5 = 5;
    for( ; j < 10000 ; j++) {
        lli nextUglyNumber = min(nextMultipleOf2,min(nextMultipleOf3,nextMultipleOf5)) ;   //min(dp[i2]*2,min(dp[i3]*3,dp[i5]*5)) ;
        
        dp.pb(nextUglyNumber) ;

        if(nextUglyNumber == nextMultipleOf2){
            i2++;
            nextMultipleOf2 = dp[i2]*2;
        }
        if(nextUglyNumber == nextMultipleOf3){
            i3++;
            nextMultipleOf3 = dp[i3]*3;
        }
        if(nextUglyNumber == nextMultipleOf5) {
            i5++;
            nextMultipleOf5 = dp[i5]*5;
        }
    }
   // for(int j=0;j<100;j++){        cout << "dp["<<j<<"] = "<< dp[j] << endl;    }
}

int main() {
    generateUglyNumbers();
    int testCases;
    cin >> testCases;
    while(testCases--){
        int n ;
        cin >> n;
        cout << dp[n] << endl ;
    }


    return 0;
}

