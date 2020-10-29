//You are provided an array of numbers. You need to arrange them in a way that yields the largest value.

//Input Format:
//First line contains integer t which is number of test case. For each test case, it contains an integer n which is the size of array A[] and next line contains n space separated integers A[i] .

//Constraints:
//1<=t<=100
//1<=m<=100
//1<=A[i]<=10^5

//Output Format:
//Print the largest value.

//Sample Input:
//1
//4
//54 546 548 60

//Sample Output:
//6054854654


#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
bool myCompare(string a,string b)
{
    string s1=a.append(b);
    string s2=b.append(a);
    return s1>s2;
}
int main() 
{
    int testCases;
    cin>>testCases;
    int n,i;
    string s[101];
    while(testCases--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>s[i];
        }
        sort(s,s+n,myCompare);
        for(i=0;i<n;i++)
        {
            cout<<s[i];
        }
        cout<<endl;
    }

    return 0;
}
