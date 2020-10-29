/*
PMO gives two random numbers a & b to the Prime Minister. PM Modi wants to visit all countries between a and b (inclusive) , 
However due to shortage of time he can't visit each and every country , So PM Modi decides to visit only those countries,
for which country number has two divisors. So your task is to find number of countries Mr. Modi will visit.


Input Format:
The first line contains N , no of test cases. The next lines contain two integers a and b denoting the range of country numbers.

Constraints:
a<=1000000 & b<=1000000.
N<=1000

Output Format:
Output contains N lines each containing an answer for the test case.

Sample Input:
2
1 10
11 20
Sample Output:
4
4
Time Limit: 1 sec
*/
#include <iostream>
#define size 1000000
using namespace std;
bool sieve[size];
void createSieve(){
    for(long i=0;i<size;i++){
        sieve[i] = true;
    }
    sieve[0] = sieve[1] = false;
    for(long i=2;i<size;i++){
        for(long j=i*i;j<size;j+=i){
            sieve[j] = false;
        }
    }
}

long countPrimes(long a,long b){
    long c = 0;
    for(;a<=b;a++){
        if(sieve[a])
            c++;
    }
    return c;
}

int main() {
    createSieve();
    int testCases;
    cin>>testCases;
    while(testCases--){
        long a,b;
        cin>>a>>b;
        cout<<countPrimes(a,b)<<endl;
    }

    return 0;
}

