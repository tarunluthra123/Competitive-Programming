/*
Similar Chocolates
There are N chocolates denoted by array A where A[i] is the length of the i-th chocolate. Alice can melt each chocolate
and then convert it into a chocolate whose length is any divisor of the number . So, a chocolate of length A[i] can be
converted into X different types of chocolate where X is the count of divisors of the number .
So you need to count the total unordered pair of chocolates such that their X value is same.

Input Format
The first line contains an integer N as input denoting the total number of elements in the array .
The next line contains N space-separated integers that denote the elements of the array A.

Output Format
In the output, print the total number of ways as mentioned in the statement.

Constraints

SAMPLE INPUT
3
2 3 4
SAMPLE OUTPUT
1

*/
#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;
int countDivisors(long n){
    int c = 2;  //1 and n itself are two factors atleast
    long k = n;
    for(long i=2;i<n;i++){
        if(k%i == 0){
            c+=2;
            n=k/i;
            if(i*i == k)    c--;
        }
    }
    return c;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_map< int, int > m;
  //  unordered_map<int,int> m ;  // <x,freq> pair
    int n = 0;
    cin >> n;

    long chocolate ;
    for(int i=0;i<n;i++){
        cin >> chocolate ;
        int x = countDivisors(chocolate);
        if(m.find(x)==m.end()){
            m[x] = 1;
        }
        else {
            m[x]++;
        }
	//	cout <<" i-"<<i<<"      m[x]="<<m[x]<<"     x="<<x<<endl;
	//6
//  2 3 4 5 9 11
    }
    int ans = 0 ;
    for(auto it=m.begin();it!=m.end();it++){
        int p = it->second ;
       // cout << "p ="<< p << " ans="<<ans<<endl;
        ans += (p*(p-1)/2);
    }
    cout << ans ;


    return 0;
}

