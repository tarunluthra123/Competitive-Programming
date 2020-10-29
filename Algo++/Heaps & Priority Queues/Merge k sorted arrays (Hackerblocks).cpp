//Merge k sorted arrays 
/*
MERGE K SORTED ARRAYS
Given K sorted arrays each with N elements merge them and output the sorted array


Input Format:
First line contains 2 integers K and N.

K is number of arrays.

N is number of elements in each array.

Constraints:
Elements of array <= |10^15|
N <= 10^5
K <= 10

Output Format:
Single line consisting of space separated numbers

Sample Input:
3 4
1 3 5 7
2 4 6 8
0 9 10 11
Sample Output:
0 1 2 3 4 5 6 7 8 9 10 11
Time Limit: 2 sec
*/
#include <bits/stdc++.h>
using namespace std;

struct ArrayPair {
    long name ;     
    long data ;
};

//Functor
class MyCompare {
public :
    bool operator()(ArrayPair a,ArrayPair b){
        return a.data > b.data ; 
    }
};

#define minHeap priority_queue< ArrayPair , vector<ArrayPair> , MyCompare >

int main() {
    minHeap pq ;
    long a[100][100005];
    long k ;    //No of arrays
    cin >> k ; 
    long n;     //Size of each array
    cin >> n;
    for(long i=0;i<k;i++){
        for(long j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    long current[k] = {0};      //current pointer for each array
    long totalSize = n*k ;      //size of final sorted array

    //Push the first element of each array into the heap along with their names as an ArrayPair object
    for(long i=0;i<k;i++){
        ArrayPair p ;
        p.name = i;
        p.data = a[i][0];
        pq.push(p);
        current[i]++;
    }

    vector<long> finalArray;

    while(totalSize--){
        ArrayPair p = pq.top() ;
        pq.pop() ; 
        finalArray.push_back(p.data);
        if(current[p.name] >= n){
            //this array is empty
            p.data = INT_MAX  ;
        }
        else {
            p.data = a[p.name][current[p.name]] ; 
        }

        //Push next element from the same array
        pq.push(p);
        current[p.name]++;
    }

    for(long i=0;i<finalArray.size();i++){
        cout<<finalArray[i]<<" ";
    }

    return 0;
}

