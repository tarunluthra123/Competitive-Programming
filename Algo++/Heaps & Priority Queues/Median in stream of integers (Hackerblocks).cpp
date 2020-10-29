/*
MEDIAN IN A STREAM OF RUNNING INTEGERS
You are given a running data stream of n integers. You read all integers from that running data stream and find effective median of elements read so far in efficient way. All numbers are distinct in the data stream.


Input Format:
First line contains integer t as number of test cases. Each test case contains following input. First line contains integer n which represents the length of the data stream and next line contains n space separated integers.

Constraints:
1 < t < 100
1< n < 1000

Output Format:
Print the effective median of running data stream..

Sample Input:
1
6
5 15 1 3 2 8
Sample Output:
5 10 5 4 3 4
Explanation:
Read print 5 5 5 15 ([5+15]/2)=10 5 15 1 (1 5 15) 5 5 15 1 3 (1 3 5 15) (5+3)/2 = 4 So on….
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int testCases ; 
    cin >> testCases ; 
    while(testCases--){
        long n ;
        long median ;
        priority_queue<long , vector<long> , greater<long> > minHeap ; 
        priority_queue<long> maxHeap ; 
        int minSize = 0 ;
        int maxSize = 0 ;
        int size ;
        cin >> size ;
        /*
        cin >> n;       //First input
        minHeap.push(n);
        minSize ++ ; 
        median = n ;
        */
        median = 0;
        while(size--){
            //Query point
          //  cout<<median<<" " ; 

            cin >> n;

            if(n < median){
                maxHeap.push(n);
                maxSize ++ ; 
            }
            else {
                minHeap.push(n);
                minSize ++ ; 
            }
            if(abs(minSize - maxSize) == 2){
                //Imbalance
                if(minSize > maxSize){
                    long temp = minHeap.top() ; 
                    minHeap.pop() ; 
                    minSize -- ;
                    maxHeap.push(temp);
                    maxSize ++ ; 
                }
                else {
                    long temp = maxHeap.top();
                    maxHeap.pop(); 
                    maxSize--;
                    minHeap.push(temp);
                    minSize++;
                }
            }

            //Recalculate median after every iteration
            if(minSize == maxSize){
                median = ( minHeap.top() + maxHeap.top() )/ 2 ;
            }
            else if(minSize > maxSize){
                median = minHeap.top() ;
            }
            else {
                median = maxHeap.top() ;
            }

            cout << median << " ";
        }
        cout<<endl;
    }


    return 0;    
}

