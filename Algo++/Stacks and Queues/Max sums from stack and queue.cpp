/*
You are given a stack of N integers such that the first element represents the top of the stack and the last element represents the bottom of the stack. You need to pop at least one element from the stack. At any one moment, you can convert stack into a queue. The bottom of the stack represents the front of the queue. You cannot convert the queue back into a stack. Your task is to remove exactly K elements such that the sum of the K removed elements is maximised.

Input format :     

The first line consists of two space-separated integers N and K.
The second line consists of N space-separated integers denoting the elements of the stack.
Output format :

Print the maximum possible sum of the K removed elements
Constraints :

1
=
N
=
10
5
1
=
K
=
N
1
=
A
i
=
10
9
SAMPLE INPUT 
10 5
10 9 1 2 3 4 5 6 7 8
SAMPLE OUTPUT 
40
Explanation
Pop two elements from the stack. i.e {10,9}

Then convert the stack into queue and remove first three elements from the queue. i.e {8,7,6}.

The maximum possible sum is 10+9+8+7+6 = 40
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    long long a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    long long s = 0;
    for(int i=0;i<k;i++) {
        s += a[i];
    }
    long long m=s;

    for(int i=0;i<k-1;i++) {
        s = s + a[n-1-i] - a[k-1-i];
        if(s >= m) {
            m = s;
        }
    }

    cout<<m;

    return 0 ;
}

