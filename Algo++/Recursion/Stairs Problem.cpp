/*
Simran and stairs


Simran is running up a staircase with N steps, and can hop(jump) either 1 step, 2 steps or 3 steps at a time.You have to count, how many possible ways Simran can run up to the stairs.

Input Format:
Input contains integer N that is number of steps

Output Format:
Output for each integer N the no of possible ways w.

Constraints
1<=N<=30

SAMPLE INPUT 
4
SAMPLE OUTPUT 
7

*/
#include <iostream>
using namespace std;
//f(n) = f(n-1) + f(n-2) + f(n-3)
int steps(int n)
{
    if(n==0||n==1)
        return 1;
    if(n==2)
        return 2;
    
    return steps(n-1)+steps(n-2)+steps(n-3);
}
int main() 
{
    int n;
    cin>>n;
    cout<<steps(n);
    return 0;
}

