/*
Prateek recently graduated from college. To celebrate, he went to a candy shop and bought all the candies. The total cost was a number upto which there are n prime numbers (starting from 2). Since Prateek wants to minimize his cost, he calls you to help him find the minimum amount that needs to be paid. Being a student of Prateek bhaiya it is now your job to help him out :)


Input Format:
First line contains a single integer denoting the number of test cases T. Next T lines contains a single integer N, denoting the number of primes required.

Constraints:
T <= 10000


It is guaranteed that the answer does not exceed 10^6.

Output Format:
Print the minimum cost that needs to be paid.

Sample Input:
2
5
1
Sample Output:
11
2
Explanation:
In the first case there are 5 primes upto 11(2,3,5,7,11).

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

int brain[size];
void createBrain(){
    brain[0] = 1;
    brain[1] = 2;
    brain[2] = 3;
    brain[3] = 5;
    long j = 7;
    for(long i=4;i<size;i++){
        for(;j<size;j++){
            if(sieve[j]){
                brain[i] = j;
                j++;
                break;
            }
        }
    }
}

int main() {
    createSieve();
    createBrain();
    long testCases;
    cin>>testCases;
    while(testCases--){
        long n;
        cin>>n;
        cout<<brain[n]<<endl;
    }

    return 0;
}
