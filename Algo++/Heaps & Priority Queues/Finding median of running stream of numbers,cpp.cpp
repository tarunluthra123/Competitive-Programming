//Find  the median of a running stream of numbers .
//-1 is used as a query point
#include <bits/stdc++.h>
using namespace std;
int main() {
    long n ;
    long median ;
    priority_queue<long , vector<long> , greater<long> > minHeap ; 
    priority_queue<long> maxHeap ; 
    int minSize = 0 ;
    int maxSize = 0 ;
    cin >> n ;
    minHeap.push(n);
    minSize ++ ; 
    median = n ;
    while(scanf("%ld",&n)!=EOF){
        if(n == -1){
            //Query point
            cout<<median<<endl ; 
            continue ;
        }
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

    }



    return 0;    
}

