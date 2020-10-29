/*
You have been given an integer array A and a number K. Now, you need to find out whether any two different elements of the array A sum to the number K. Two elements are considered to be different if they lie at different positions in the array. If there exists such a pair of numbers, print "YES" (without quotes), else print "NO" without quotes.

Input Format:

The first line consists of two integers N, denoting the size of array A and K. The next line consists of N space separated integers denoting the elements of the array A.

Output Format:

Print the required answer on a single line.

Constraints:




SAMPLE INPUT 
5 9
1 2 3 4 5
SAMPLE OUTPUT 
YES
*/
#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    unordered_map<long,long> h ;    //Value,index pair
    long n,k;
    cin >> n >> k;
    long temp,a[n];
    for(long i=0;i<n;i++){
        cin >> a[i] ;
        h[a[i]] = i;
    }
    bool ans = false ;
    for(long i=0;i<n;i++){
        long x = k-a[i];
        if(h.find(x)!=h.end() && h[x]!=i){
            ans = true ;
            break ;
        }
    }
    if(ans){
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}

