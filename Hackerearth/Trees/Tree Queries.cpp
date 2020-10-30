/*

https://www.hackerearth.com/practice/data-structures/trees/binary-and-nary-trees/practice-problems/algorithm/tree-queries-45/

Tree Queries
There is a complete Binary tree in which there are N nodes. Each vertex of the tree is assigned a value.

You are given the values of all nodes in level order traversal of the binary tree (from left to right).

You are given three types of queries.

1 X  LV  Find the value of Xth node from left on the level LV.

2  L R  Find the the sum of values of nodes from level L to R (L and R are inclusive). 

3  X  LV  VAL Update the value of Xth node from left which is at level LV to VAL. 

Note: Root is at level 1.

INPUT

In the first line you are given two integers N, Q.

In the next line you are given an array A where the ith value denotes the value of ith node.

In the next Q lines you are given one of the three queries.

It is guaranteed that there exists at least one query of type 1 or 2.

Also it is guaranteed all given queries are valid.

OUTPUT

For each query of 1st and 2nd type print the required value.

CONSTRAINTS





SAMPLE INPUT 
5 3
2 1 3 4 2
1 2 2
3 2 3 5
2 1 3
SAMPLE OUTPUT 
3
15
Explanation
In the First query you have to find the 2nd node at level 2 which is 3.

In the second query you have to update the 2nd node from left at level 3.

So new array looks like 2 1 3 4 5

In last query you have to find the sum of  values of all nodes from level 1 to 3.

so 2 + 1 +3 + 4 +5=15.
*/
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define FOI(i, a, n) for( i = int(a); i <= int(n); i++)
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define ll  long long int

class node {
public :
    ll d,l,p;
    node(ll dx) {
        d = dx;
        l = 0;
        p = 0;
    }
};

void xFromLeft(ll x,ll lv,vector<node> &v,ll i) {
    if(i>v.size() || v[i].l > lv) {
        return;
    }
    if(v[i].l == lv && v[i].p == x) {
        cout << v[i].d ;
        return ;
    }
    xFromLeft(x,lv,v,2*i+1);
    xFromLeft(x,lv,v,2*i+2);
}

void sumLtoR(ll l,ll r,vector<node> &v,ll &sum,ll i) {
    if(i>=v.size() || v[i].l > r) {
        return ;
    }
    if(v[i].l >= l && v[i].l <= r) {
        sum += v[i].d;
    }
    sumLtoR(l,r,v,sum,2*i+1) ;
    sumLtoR(l,r,v,sum,2*i+2) ;
}

void changeVal(ll x,ll lv,ll val,vector<node> &v,int i,bool &flag) {
    if(flag) {
        //Already changed
        return ;
    }
    if(i>=v.size() || v[i].l > lv) {
        return;
    }
    if(v[i].l == lv && v[i].p == x) {
        v[i].d = val;
        flag = true;
        return ;
    }
    changeVal(x,lv,val,v,2*i+1,flag);
    changeVal(x,lv,val,v,2*i+2,flag);
}

int main() {
	sync;
    ll n , q ,i;
    cin >> n >> q;
    vector<node> v;
    FOI(i,0,n-1) {
        ll x;
        cin >> x;
        node u(x);
        v.pb(u);
    }
    v[0].l = 1;
    v[0].p = 1;
    FOI(i,0,n-1) {
        if(2*i+1 < n) {
            v[2*i+1].l = v[i].l+1;
            v[2*i+1].p = v[i].p*2 - 1;
        }
        if(2*i+2 < n) {
            v[2*i+2].l = v[i].l+1; 
            v[2*i+2].p = v[i].p*2;
        }
    }
    
    while(q--) {
        ll query;
        cin >> query;
        if(query == 1) {
            ll x,lv;
            cin >> x >> lv;
            xFromLeft(x,lv,v,0);
            cout << endl;
        }
        else if(query == 2) {
            ll l,r;
            cin >> l >> r;
            ll sum = 0;
            sumLtoR(l,r,v,sum,0) ;
            cout << sum;
            cout << endl;
        }
        else {
            ll x,lv,val;
            cin >> x >> lv >> val;
            bool flag = false;
            changeVal(x,lv,val,v,0,flag);
        }
        
        
    }
    
	return 0;
}
