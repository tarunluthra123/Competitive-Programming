/*
UNLOCK
Shekhar is a bomb defusal specialist. He once encountered a bomb that can be defused only by a secret code. He is given a number N and a number K. And he is also given permutation of first N natural numbers . The defusal code is the largest permutation possible by doing exactly K swaps among a pair of the given permutation. Help him to find the final permutation.


Input Format:
First line contains ?an integer N and an integer k. The next line contains N space separated integers denoting the given permutation.

Constraints:
1 <= n <= 10^5 1<= K <= 10^9

Output Format:
The final permutation of the numbers with every number separated by a space with other number.

Sample Input:
5 2
3 4 1 2 5
Sample Output:
5 4 3 2 1
Explanation:
First we can swap 5 with 3 which gives us 5 4 1 2 3 and then we can swap 3 and 1 which gives us 5 4 3 2 1.

Time Limit: 2 sec

*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin >> n >> k;
    vector<int> v;
    unordered_map<int,int> m ;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
        m[v[i]] = i ;
    }
    for(int i=0;i<n && k>0;i++){
        int x = n - i;
        if(v[i] == x){
            //Already correct element
            continue;
        }
        int index = m[x];
        m[v[i]] = index ;
        m[x] = i;
        swap(v[i],v[index]);
        k--;
    }
    for(int i=0;i<n;i++){
        cout << v[i] << " ";
    }

    return 0;
}

