/*
Rajiv and Nitish had a fight because Rajiv was annoying Nitish with his question. Rajiv being a genius in arrays gave Nitish an array of natural numbers A of length N with elements A1,  A2, . . ., AN. Nitish has to find the total amount of perfect pairs in the array.
  
A perfect pair (Ai, Aj) is a pair where (Ai + Aj) is a perfect square or a perfect cube and i ? j. 
  
Since Rajiv and Nitish are not talking with each other after the fight you have been given the question to solve and inturn make both of them a perfect pair again.
  
NOTE :-  A pair (Ai, Aj) and (Aj, Ai) are same and not to be counted twice.

 

Input

The first line on the input contains the a single integer T denoting the number of test cases. The first line of each test case contains a single integer N. The second line contains N space-separated integers A1,  A2, . . ., AN.

Output

For each test case, print a single line containing a single integer denoting the total number of perfect pairs.

Constraints

1 =  T = 10
1 =  N = 105
1 =  Ai = 103

SAMPLE INPUT 
2
5
1 2 3 4 5
4
1 4 5 8
SAMPLE OUTPUT 
3
2
Explanation
In first testcase pairs (1, 3), (3, 5) and (4,5) give values 4, 8, 9 and form perfect pairs.

In the second testcase pairs (1, 8), (4, 5) give values 9, 9 and form perfect pairs.
*/

#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_map<long,int> m;
    long x = 0;
    for(int i=1;x<1000000;i++){
        x = i*i ;
        m[x] = 1;
    }    
    x = 0;
    for(int i=2;x<1000000;i++){
        x = i*i*i ;
        m[x] = 1;
    }

    int testCases; 
    cin >> testCases;
    int a[100000];
    while(testCases--){
        int n ;
        cin >> n; 
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        long count = 0 ;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                x = a[i]+a[j];
                if(m[x]){
                    //cout << a[i] << "   " << a[j] << endl ;
                    count++;
                }
            }
        }
        cout << count << "\n";
    }
    


    return 0;
}

