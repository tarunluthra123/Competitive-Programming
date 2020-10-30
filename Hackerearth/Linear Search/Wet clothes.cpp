/*
https://www.hackerearth.com/practice/algorithms/searching/linear-search/practice-problems/algorithm/wet-clothes-625348cf/

Wet clothes
We have  completely wet clothes out under sunshine waiting to become dry. we are now at second  and it's raining. It's going to rain again on seconds  and after each rain clothes will be completely wet again. Cloth number  needs  seconds to become dry. We can go out and collect all dry clothes at any moment but can't do this more than  times. What is the maximum number of clothes we can collect until second ? Note that the duration of each rain is almost zero, so we can ignore it. Also collecting clothes does not take any time from us.

Input format

First line of input contains three integers  (, ) respectively. In the second line will be  increasing numbers denoting  (). In the Last line will have  numbers denoting  ().

Output format

In a single line print maxmimum number of clothes we can collect.

SAMPLE INPUT 
3 3 2
3 5 8
4 1 3
SAMPLE OUTPUT 
2
Explanation
In the sample, first we go outside at time 5(exactly before rain) and take second piece of clothes. Then for the second time, at second 8, we go and take third piece.
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m,g;
    cin >> n >> m >> g;

    int t[n];
    int x;
    cin >> t[0];
    int prev = t[0];
    for(int i=1;i<n;i++) {
        cin >> x;
        t[i] = x - prev;
        prev = x;
    }
    //for(int i=0;i<n;i++) {        cout << t[i] << " " ;    }
    
    sort(t,t+n,greater<int>());
    
    int a[m];
    for(int i=0;i<m;i++) {
        cin >> a[i];
    }

    int c = 0 ;
    for(int i=0;i<n;i++) {
        bool flag = false;
        for(int j=0;j<m;j++) {
            if(a[j] <= t[i]) {
                c++;
                // cout << c << " " << a[j] << endl;
                a[j] = 10000000;
                flag = true;
            }

        }
        if(flag) {
            g--;
        }
        if(g<=0) {
        //    break;
        }
    }

    cout << c;

    return 0;
}

