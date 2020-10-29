/*
MINIMUM MONEY NEEDED
Cody went to the market to buy some oranges for his N friends. There he finds orange wrapped in packets, with the price of i^th packet as val[i]. Now he wants to buy exactly W kg oranges, so he wants you to tell him what minimum price he should pay to buy exactly W kg oranges. Weight of i^th packet is i kg. If price of i^th packet is -1 then this packet is not available for sale. The market has infinite supply of orange packets.


Input Format:
First line of input contains two space separated integers N and W, the number of friend he has and the amount of Oranges in kilograms which he should buy.

The second line contains W space separated integers in which the i^th^ integer specifies the price of a ‘i’kg apple packet. A value of -1 denotes that the corresponding packet is unavailable

Constraints:
1 <= N,W,val[ ] <= 10^3

Output Format:
Output a single integer denoting the minimum price Code should pay to get exactly W kg oranges. Else print -1 if it is not possible to fill the bag.

Sample Input:
5 5
1 2 3 4 5
Sample Output:
5
*/
#include <iostream>
using namespace std;
#define lli long long int

lli buyOrangesBottomUp(lli *price,lli w){
    lli dp[w+1];
    dp[0] = 0;
    for(lli i=1; i<=w; i++) {
        dp[i] = price[i];
    }

    for(lli i=2;i<=w;i++){
        for(lli j=0;j<i;j++) {
	        if(price[i-j] == -1  || dp[j] == -1){
			    continue;
			}
            if(dp[i] == -1)
                dp[i] = dp[j] + price[i-j];
            else
                dp[i] = min(dp[i], dp[j] + price[i-j]);
        }
    }

  //  for(int i=1;i<=w;i++)   cout << dp[i] << " "; 
    return dp[w];
}

int main() {
    lli n,w;
    cin>>n>>w;
    lli price[w+1];
    for(lli i=1;i<=w;i++) {
        cin>>price[i];
    }
    
    cout<<buyOrangesBottomUp(price,w)<<endl;
    
    return 0;
}

