/*
DEEPAK AND PRIMES
Deepak is learning Sieve of Eratosthenes, He is stuck somewhere. Help him printing prime numbers.


Input Format:
Single line containing integral value n.

Constraints:
1<=n<=5000000

Output Format:
Integral value denoting nth prime number.

Sample Input:
1
Sample Output:
2
Time Limit: 1 sec
*/
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

#define MAX 87000000

bitset<MAX> sieve ;
vector<unsigned long> primes ;

void createSieve(){
    for(unsigned long i=0;i<MAX;i++){
        sieve[i] = 1; 
    }
    sieve[0] = sieve[1] = 0;
    for(unsigned long i=2;i<MAX;i++){
        if(sieve[i]){
            primes.push_back(i);
            for(unsigned long j=i*i;j<MAX;j+=i){
                sieve[j] = 0;
            }
        }
    }
}
int main() {
    createSieve() ;
    long n ;
    cin >> n;
    if(n<1 || n>MAX){
        return 0;
    }

    if(n <= primes.size())
        cout << primes[n-1];

    return 0;
}

