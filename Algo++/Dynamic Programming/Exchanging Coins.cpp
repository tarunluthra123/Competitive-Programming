/*
EXCHANGING COINS
Tughlaq introduces a strange monetary system. He introduces copper coins and each coin has a number written on it. 
A coin n can be exchanged in a bank into three coins: n/2, n/3 and n/4. A coin can also be sold for gold. One can get as much grams of gold as the number written on the coin. You have one copper coin. What is the maximum weight of gold one can get from it?


Input Format:
The input file contains a single integer n, the number on the coin.

Constraints:
0 <= n <= 1 000 000 000

Output Format:
Print the maximum weight of gold you can get.

Sample Input:
12
Sample Output:
13
Time Limit: 2 sec
*/
#include <iostream>
using namespace std;
#define lli long long int
#define size 100000000

lli dp[size];

lli exchange(lli n){
    if(n<=11){
        return n;
    }
    if(n<size && dp[n]!=-1){
        return dp[n];
    }
    
    lli q1 = exchange(n/2);
    lli q2 = exchange(n/3);
    lli q3 = exchange(n/4);

    lli res = q1 + q2 + q3 ; 
    if(res < n){
        res = n ;
    }

    if(n < size)
		dp[n] = res;

    return res ;
}


int main() {

    for(lli i=0;i<size;i++){
        dp[i] = -1;
    }


    lli n;
    cin >> n;
    cout << exchange(n);


    return 0;
}

