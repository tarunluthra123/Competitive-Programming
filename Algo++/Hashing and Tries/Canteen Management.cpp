/*
coca cola canteen of Bharati Vidyapeeth university has n hungry students waiting in line. 
Each unique order, i , is placed by a student at time ti, and the order takes di units of time to process. 
Now canteen incharge wanted to know the sequence in which the orders will be completed so that order which is completed first is served first 
which resulting in less chaos in canteen during the break hours but he doesn't know how to solve this problem.
Given the information for all n orders, can you find and print the order in which all n students will receive their orders? 
If two or more orders are fulfilled at the exact same time t, sort them by ascending order number.

Input Format

The first line contains a single integer,n, denoting the number of orders. Each of the n subsequent lines contains two space-separated integers describing the respective values of ti and di for order.

Constraints

1 <= n <= 1000
1 <= i <=n
1 <= ti,di <=1000000
Output Format

Print a single line of space-separated order numbers describing the sequence in which the students receive their orders. If two or more students receive their order at the same time, print the smallest order number first.

SAMPLE INPUT 
5
8 1
4 2
5 6
3 1
4 3
SAMPLE OUTPUT 
4 2 5 1 3
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
    int n ; 
    cin >> n;
    map <long, vector<int> > m; //<time , vector of indices> pair
    long t[n],d[n];
    for(int i=0;i<n;i++){
        cin >> t[i] >> d[i];
        long time = t[i]+d[i];
        m[time].push_back(i+1);
    }
    for(auto it=m.begin();it!=m.end();it++){
        for(int j=0;j<it->second.size();j++){
            cout << it->second[j] << " ";
        }
    }




    return 0;
}

