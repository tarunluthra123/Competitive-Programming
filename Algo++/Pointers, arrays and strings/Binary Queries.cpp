//Binary Queries
/*
Some problems appear hard though they are very easy. Today Aakash is stuck in a range query problem. He has been given an array with only numbers 0 and 1. There are two types of queries -

0 L R : Check whether the number formed from the array elements L to R is even or odd and print EVEN or ODD respectively. Number formation is the binary number from the bits status in the array L to R

1 X : Flip the Xth bit in the array 

Indexing is 1 based

Input
First line contains a number N and Q as input. Next line contains N space separated 0 or 1. Next Q lines contain description of each query 

Output
Output for only query type 0 L R whether the number in range L to R is "EVEN" or "ODD" (without quotes).

Constraints
1= N = 10^6 
1= L = R = 10^6 
1= Q = 10^6

1= X = N

SAMPLE INPUT 
5 2
1 0 1 1 0
1 2
0 1 4
SAMPLE OUTPUT 
ODD

*/

#include <iostream>
using namespace std;
void flip(int *a,long x){
    //Flip xth bit
    if(a[x]==0){
        a[x] = 1;
    }
    else {
        a[x] = 0;
    }
}
void checkOddEven(int *a,long r){
    if(a[r]){
        cout<<"ODD";
    }
    else {
        cout<<"EVEN";
    }
}
int main() {
    long n,r,l,q,x;
    cin >> n >> q;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    while(q--){
        int p ; 
        cin >> p ;
        if(p == 0){
            cin >> l >> r;
            checkOddEven(a,r);
            cout<<endl ; 
        }
        else {
            int x ; 
            cin >> x;
            flip(a,x) ; 
        }
    }

    return 0; 
}

