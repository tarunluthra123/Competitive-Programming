#include <bits/stdc++.h>
using namespace std;

double dp[301][301][301];

double sushi(int x,int y,int z,int &n) {
    if(x<0 || y<0 || z<0) 
        return 0;
    if(x==0 && y==0 && z==0)
        return 0;
    if(dp[x][y][z] > -0.9)
        return dp[x][y][z];
    
    double exp = n + x*sushi(x-1,y,z,n) + y*sushi(x+1,y-1,z,n) + z*sushi(x,y+1,z-1,n);
    return dp[x][y][z] = exp/(x+y+z);

}

int main() {
    int n;
    cin>>n;

    int one=0;
    int two=0;
    int three=0;

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin>>x;
        if(x==1)
            one++;
        else if(x==2)
            two++;
        else
            three++;
    }

    memset(dp,-1,sizeof dp);

    cout << fixed << setprecision(10) << sushi(one,two,three,n) << "\n";

    return 0;
}