/*
HOTEL VISIT
Dean of MAIT is going to visit Hostels of MAIT. As you know that he is a very busy person so he decided to visit only first "K" nearest Hostels. Hostels are situated in 2D plane. You are given the coordinates of hostels and you have to answer the Rocket distance of Kth nearest hostel from origin ( Dean's place ) .


Input Format:
First line of input contains Q Total no. of queries and K There are two types of queries:

first type : 1 x y For query of 1st type, you came to know about the co-ordinates ( x , y ) of newly constructed hostel. second type : 2 For query of 2nd type, you have to output the Rocket distance of Kth nearest hostel till now.

The Dean will always stay at his place ( origin ). It is gauranted that there will be atleast k queries of type 1 before first query of type 2.

Rocket distance between two points ( x2 , y2 ) and ( x1 , y1 ) is defined as (x2 - x1)2 + (y2 - y1)2

Constraints:
1 < = k < = Q < = 10^5
-10^6 < = x , y < = 10^6 

Output Format:
For each query of type 2 output the Rocket distance of Kth nearest hostel from Origin.

Sample Input:
9 3
1 10 10
1 9 9
1 -8 -8
2
1 7 7
2
1 6 6 
1 5 5
2
Sample Output:
200
162
98
Time Limit: 2 sec
*/
#include <iostream>
#include <queue>
#define ll long long int
using namespace std;
int main() {
    ll q,k;
    cin >> q >> k;

    priority_queue<ll> pq;
    while(q--){
        ll query ;
        cin >> query;
        if(query == 1){
            ll x,y;
            cin >> x >> y;
            ll dist = x*x + y*y ;
            if(pq.size() < k){
                pq.push(dist);
            }
            else if(dist < pq.top()){
                pq.pop();
                pq.push(dist);
            }
        }
        else {
            cout << pq.top() << endl;
        }
    }

    return 0;
}

