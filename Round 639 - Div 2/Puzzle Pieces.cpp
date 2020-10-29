#include <bits/stdc++.h>
using namespace std;

int main() {
    int testCases;
    cin >> testCases;
    while (testCases--) {
        int a,b;
        cin>>a>>b;
        if(a==1||b==1||(a==2&&b==2)){
            cout<<"YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}
