/*
TOP K MOST FREQUENT NUMBER IN A STREAM
Given an array of n numbers. Your task is to read numbers from the array and keep at-most K numbers at the top (according to their decreasing frequency) every time a new number is read. We basically need to print top k numbers sorted by frequency when input stream has included k distinct elements, else need to print all distinct elements sorted by frequency. If frequency of two numbers are same then print them in increasing order.


Input Format:
First line contains integer t as number of test cases. Each test case contains following input. First line contains integer n which represents the length of the array and next line contains n space separated integers.

Constraints:
1 < t < 100
1< n < 100000

Output Format:
Print top k running stream.

Sample Input:
1
5 2
5 1 3 5 2
Sample Output:
5 1 5 1 3 5 1 5 1
*/
#include <bits/stdc++.h>
using namespace std;

struct NumFreqPair {
    long number ; 
    long frequency ; 
};

#define nfp NumFreqPair

class MyCompare {
public: 
    bool operator()(nfp a,nfp b){
        if(a.frequency == b.frequency){
            return a.number > b.number ; 
        }
        
        return a.frequency < b.frequency ; 
    }
};

#define maxHeap priority_queue<nfp, vector<nfp> , MyCompare >

maxHeap insert(long value,maxHeap pq){
    maxHeap h ;
    bool gotIt = false ;
    while(!pq.empty()){
        nfp x = pq.top();
        pq.pop() ;
        if(x.number == value){
            x.frequency++;
            gotIt = true ; 
        }
        h.push(x);
    }
    if(!gotIt){
        //New entry to list
        nfp x;
        x.number = value ;
        x.frequency = 1;
        h.push(x);
    }
    return h ;
}

void print(maxHeap pq,long k){
    while(!pq.empty() && k--){
        nfp x = pq.top();
        pq.pop();
      //  cout<<x.number<<" "<<x.frequency<<endl;
        cout << x.number << " ";
    }
}

int main() {
    int testCases ;
    cin >> testCases ; 
    while(testCases--){
        maxHeap pq ;
        long k,n ; 
        cin >> n >> k;
        long temp ; 
        for(long i=0;i<n;i++){
            cin >> temp ; 
            pq = insert(temp,pq);
            print(pq,k);
           // cout<<endl;
        }
    }




    return 0;
}

