/*
PAINTER PROBLEM
You have to paint N boards of length {A0, A1, A2, A3 … AN-1}. There are K painters available and you are also given how much time a painter takes to paint 1 unit of board. You have to get this job done as soon as possible under the constraints that any painter will only paint contiguous sections of board. Return the ans % 10000003


Input Format:
1<=N<=100000 1<=K<=100000 1<=T<=1000000 1<=Li<=100000

Constraints:
1<=N<=100000
1<=K<=100000
1<=T<=1000000
1<=Li<=100000

Output Format:
Return minimum time required to paint all boards % 10000003.

Sample Input:
2
2          
5
1 10
Sample Output:
50
*/
#include <iostream>
using namespace std;
#define ll long long int
#define MOD 10000003

bool isValidConfig(ll *walls,ll n,ll k,ll ans,ll t){
    ll painters = 1;
    ll timeTaken = 0;
    for(ll i=0;i<n;i++){
        if(timeTaken + (walls[i]*t) > ans){
            timeTaken = walls[i]*t;
            painters++ ;
            if(painters > k){
                return false;
            }
        }
        else {
            timeTaken += (walls[i]*t);
        }
    }
    return true ;
}

ll painterProblem(ll *walls,ll n,ll k,ll t){
    ll totalTime = 0;           //Time taken if all walls are painted by a single painter
    ll s = 0 ;
    for(ll i=0;i<n;i++){
        totalTime += walls[i];
        s = max(s,walls[i]);
    }

    s *= t;
    totalTime *= t;

    ll e = totalTime ;

    ll finalAns = s;

    while(s <= e){
        ll mid = (s+e)/2;
        if(isValidConfig(walls,n,k,mid,t)){
            finalAns = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }

    return finalAns % MOD;
}


int main() {
    ll n ;      //No of walls
    cin >> n;
    ll k ;      //No of painters
    cin >> k;
    ll t;       //Time taken by each painter for one wall
    cin >> t;

    ll a[n];
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }

    cout << painterProblem(a,n,k,t) << endl;


    return 0;
}

