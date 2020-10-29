/*
Given three numbers a,b,c. Calculate (a^b)mod c.


Input Format:
Single line containing three integers a,b,c separated by space.

Constraints:
1<=a,b,c<=100000

Output Format:
Print (a^b)mod c.

Sample Input:
2 2 3
Sample Output:
1
Explanation:
(2^2)mod 3=4 mod 3 = 1

Time Limit: 1 sec
*/
#include <iostream>
using namespace std;
#define ll long long int

ll power(ll a,ll b,ll c){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a%c;
    }
    ll smallAns = power(a,b/2,c);
    if(b & 1){
        return (smallAns*smallAns*a)%c;
    }

    return (smallAns*smallAns)%c;
}
int main() {
    ll a,b,c;
    cin >> a >> b >> c;
    cout << power(a,b,c);



    return 0;
}


