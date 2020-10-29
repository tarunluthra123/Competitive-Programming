/*
PYTHAGORAS TRIPLET
Given a number N (denoting one of the legs of the triangle), Print its Pythagoras pair in increasing order if they exist. Otherwise, print "-1".


Input Format:
A single integer N

Constraints:
N <= 10^9

Output Format:
Two numbers X and Y denoting the rest of the numbers of the Pythagorean triplet in increasing order.

Sample Input:
3
Sample Output:
4 5
Time Limit: 1 sec

*/
#include <iostream>
using namespace std;
int main() {
    long N ;
    cin >> N  ;
    long a,b,c;
    if(N <= 1){
        cout << "-1";
        return 0;
    }
    if(N&1){
        //N is odd
        a = N ; 
        b = (N*N -1)/2 ;
        c = (N*N +1)/2 ;
        cout << b << " " << c;
    }
    else {
        //N is even
        b= N ; 
        a = (N/2)*(N/2) - 1;
        c = (N/2)*(N/2) + 1;
        cout << a << " " << c;
    }


    return 0;
}

