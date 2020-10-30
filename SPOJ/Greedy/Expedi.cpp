#include <bits/stdc++.h>
using namespace std;
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007

#define ff first
#define ss second

#define ll  long long
#define pii pair<ll, ll> 
#define vi  vector<ll>

template<class T>
using maxPQ = priority_queue<T>;
template<class T>
using minPQ = priority_queue<T,vector<T>,greater<T> >; 

int expedi(vector<pii> &arr,int distance,int currentFuel){
    vector<int> v(distance+1);
    for (int i = 0; i < arr.size(); ++i) {
        v[distance-arr[i].ff] = arr[i].ss;
    }
    // int maxReach = currentFuel;
    int step = currentFuel;
    int jump = 0;
    maxPQ<ll> pq;
    for(int i=1;i<v.size();i++){
        if(i==distance){
            return jump;
        }
        if(v[i])
            pq.push(v[i]);
        step--;

        if(step==0){
            if(pq.empty())
                return -1;
            // step=maxReach;
            jump++;

            step = pq.top();
            pq.pop();
        }
    }
    return -1;
}

int main() { 
    sync;
    int testCases;
    cin >> testCases;
    while (testCases--) {
        int n;
        cin>>n;
        vector<pii> v(n);
        for (int i = 0; i < n; ++i) {
            cin>>v[i].ff>>v[i].ss;
        }
        int currentFuel, distance;
        cin>>distance>>currentFuel;

        cout << expedi(v,distance,currentFuel) << '\n';

    }

    return 0;
}
