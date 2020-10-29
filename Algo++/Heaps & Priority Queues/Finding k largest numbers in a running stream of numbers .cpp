//Finding k largest numbers in a running stream of numbers 
#include <bits/stdc++.h>
using namespace std;
#define minPQ priority_queue<int,vector<int>,greater<int> >

void query_print(minPQ pq){
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl ;
}

int main() {
    minPQ pq;
    long n;
    long k = 3;
    long currentSize = 0;
    while(scanf("%ld",&n)!=EOF){
        if(n == -1){
            //Query point - Print the largest k elements
            query_print(pq) ;
        }
        else if(currentSize < k){
            pq.push(n);
            currentSize++;
        }
        else {
            if(n > pq.top()){
                pq.pop() ; 
                pq.push(n);
            }
        }
    }
    

    return 0;
}

