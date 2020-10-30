/*
https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/hunny-bunny-eebee22a/

Poisonous Gas

You are in a battle field and your enemy has an army of N soldiers. Each soldier has a strength denoted by an array A. Your enemy will select some soldiers such that total strength of selected soldiers is maximum. You have a poisonous gas and you can use it on the selected soldiers as many times as you want. If the total strength is even, the poisonous gas will decrease the total strength of the selected soldiers to half of the total strength, otherwise it will not affect them. Your task is to tell if its possible to reduce the total strength to 1 or not.

 

Input Format:

First line contains an integer T, denoting the number of test cases.

First line of each test case contains an integer N, denoting the number of soldiers.

Second line of each test case contains N space-separated integers, denoting the strength of the soldiers.

 

Output Format:

For each test case, print Yes if its possible to reduce the total strength to 1, otherwise print No.

 

Constraints:

1<=T<=10

1<=N<=10^5

-10^9<=A[i]<=10^9

SAMPLE INPUT 
2
5
76 56 -21 76 -45
2
8 -4
SAMPLE OUTPUT 
No
Yes


*/



#include <iostream>
using namespace std;

bool ispowerof2(long num)
{
    return !(num & (num-1));
}

int main()
{
    long test,n,a[100000],i;
    cin>>test;
    long sum=0;
    while(test--)
    {
        sum=0;
        cin>>n;
        for(i=0;i<n;i++)
        {   
            cin>>a[i];
            if(a[i]>0)
            sum+=a[i];
        }
        if(ispowerof2(sum)&&sum)                //&& sum for a special case of 0 ...if sum=0 then gives wrong output otherwise
        cout<<"Yes";
        else
        cout<<"No";
        cout<<endl;
    }


    return 0;
}
