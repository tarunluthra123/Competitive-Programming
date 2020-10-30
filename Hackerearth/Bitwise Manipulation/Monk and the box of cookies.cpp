/*
Monk and the box of cookies
Suzie came over to Monk's place today with a box of Monk's favorite cookies! But Monk has to play a game with her in order to win the cookies.
Suzie takes out N balls from her bag, each ball having an integer on it. All the integers are 32-bit. She places all these balls in a box and closes it. The game starts by Monk choosing an integer from 0 to 31, representing a bit position. It is called as Monk's chosen bit. Post this, Suzie draws 1 balls from the box randomly and notes the integers on them. The rule is simple, Monk wins if Monk's chosen bit is set in the binary representation of the drawn ball. Help Monk choose a bit that maximizes his probability of winning the game! If there are multiple bit positions having the same probability, choose the smallest one.

Input:
The first line consists of an integer T. T testcases follow. The first line of each testcase consists of an integer N.
In next N lines, each line will contain 1 integer denoting the integers on the ball.

Output:
For each testcase, print the answer in a single line.

Constraints:
1<=T<=10
 
2<=N<=10^4

0<=Integers<=2147483647

SAMPLE INPUT 
1
4
2
4
2
8

SAMPLE OUTPUT 
1

*/



#include <iostream>
using namespace std;
int main() 
{
    int a[32]={0},test,i,j,temp,ans,n;
    cin>>test;
    while(test--)
    {
        cin>>n;
        for(i=0;i<32;i++)
            a[i]=0;
        for(i=0;i<n;i++)
        {
            j=0;
            cin>>temp;
            while(temp)
            {
                a[j]=a[j]+(temp&1);
                temp=temp>>1;
                j++;
            }
        }
        int maxValue=0;
        for(i=0;i<32;i++)
        {
            if(a[i]>maxValue)
            {
                ans=i;
                maxValue=a[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

