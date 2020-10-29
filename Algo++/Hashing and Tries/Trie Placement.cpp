/*
This placement season , Avinash is preparing for his upcoming interviews in multinational companies . He is trying to solve a problem which was previously asked in many companies. There is an array named arr. He is supposed to find the maximum value of (arr[a] ^ arr[a + 1] ^ arr[a + 2] …….. arr[b]) + (arr[c] ^ arr[c + 1] ^ arr[c + 2] …….. arr[d]) where 1 <= a <= b <= c <= d <= N , where N is the size of the array. Help him to find an optimal solution.


Input Format:
First line of the test case will be the length of array N . Then on the next line you will be given N space separated integers.

Constraints:
0 <= element of array <= 10^9 
1 <= N <= 10^5

Output Format:
The output contains a single integer denoting the maximum value of expression

Sample Input:
4 
1 2 6 8
Sample Output:
17
Explanation:
Here in the given a=1, b= 2, c= 3, d=4 , so (1 ^ 2) + (6 ^ 8) = 3 + 14 = 17.





We can construct two arrays lbest and rbest for the left hand side of the expression and for the
right hand side of the expression.
To calculate lbest[i] we will iterate m from i to i such that (arr[m] ^ arr[m+1] ^ arr[m+2] ....
arr[i]) is maximised. Then lbest[i] = Max(lbest[i-1], val). Similar can be done for rbest. Now we
will calculate val. Let C[i] = (arr[1] ^ arr[2] ^ arr[3] .... arr[i]). For some j <= i, C[j-1] ^ C[i] = (
arr[j] ^ arr[j+1] ^ arr[j+2] ... arr[i] ). We can now say that lbest[i] = max(lbest[i-1],val) where
val = maximum of (C[j-1]C[i]) for j = 1 to i. Now using Tries we can easily calculate ‘val’ in (log
arr(max)). We can store the bits of each number in the nodes of trie and iterate through the trie
such that we can get the maximum xor possible.
*/
#include <bits/stdc++.h>
using namespace std ;

class node {
public :
    node *left ;
    node *right ;
    node(){
        left = right = NULL ; 
    }
};

class Trie {
private :
    node *root ;
public :
    Trie(){
        root = new node() ; 
    }
    void insert(int n){
        node *temp = root ;
        for(int i=31 ;i>=0;i--){
            int bit = (n >> i) & 1;
            if(bit == 0){
                if(temp->left == NULL){
                    temp->left = new node() ;
                }
                temp = temp->left ;
            }
            else {
                if(temp->right == NULL){
                    temp->right = new node() ;
                }
                temp = temp->right ;
            }
        }
    }
    int findMaxXorPair(int value){
        node *temp = root ;
        int currentXor = 0 ;
        for(int j=31 ;j>=0 ; j--){
            int bit = (value >> j) & 1;
            if(bit == 0){
                if(temp->right != NULL){
                    temp = temp->right ;
                    currentXor += (1<<j);
                }
                else {
                    temp = temp->left ;
                }
            }
            else {
                if(temp->left != NULL){
                    temp = temp->left ;
                    currentXor += (1<<j);
                }
                else {
                    temp = temp->right ;
                }
            }
        }
        return currentXor ; 
    }
};

int main() {
    int n ;
    cin >> n;
    int result = 0;
    int arr[n];
    int lbest[100000] ;
    int rbest[100000] ;
    int left_value = 0,right_value = 0;
    Trie tl;
    tl.insert(0);
    for(int i=0;i<n;i++){
        cin >> arr[i] ;
        left_value ^= arr[i];
        lbest[i] = max( (i == 0)? 0 : lbest[i-1] , tl.findMaxXorPair(left_value));
        tl.insert(left_value);
    }
    
    Trie tr ;
    tr.insert(0);
    for(int i=n-1;i>=0;i--){
        right_value ^= arr[i];
        rbest[i] = max((i == n - 1) ? 0 : rbest[i + 1],tr.findMaxXorPair(right_value));
        tr.insert(right_value);   
        int val = rbest[i] + (i == 0 ? INT_MIN : lbest[i - 1]);
        result = max(result,val);
    }
    cout << result ;

    return 0 ;
}
