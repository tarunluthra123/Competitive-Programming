/*
Given a string containing duplicates, print all its distinct permutations such that there are no duplicate permutations and all permutations are printed in a lexicographic order.

NOTE: DO NOT USE MAP OR SET.


Input Format:
The first and only line of the test case contains the input string.

Constraints:
Length of the string <= 8

Output Format:
Print all the distinct permutations in a lexicographic order such that each permutation is in a new line. Note that there should not be any duplicate permutations.

Sample Input:
ABA
Sample Output:
AAB
ABA
BAA


*/



//Tricky Permutations
//https://hack.codingblocks.com/contests/c/537/737
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

string ans[100000];
int c = 0;

void permute(string inp,int i)
{
    //Base case
    if(i == inp.size())
    {
        ans[c++] = inp;
        return ;
    }

    //Recursive case
    for(int j = i;j<inp.length() ; j++)
    {
        swap(inp[i],inp[j]);
        permute(inp,i+1);
        swap(inp[i],inp[j]);    //Backtrack
    }
}

int main() 
{
    string input;
    cin>>input;

    permute(input,0);
    sort(ans,ans+c);

    string temp = "";
    for(int i = 0;i<c;i++)
    {
        if(temp != ans[i])
            cout<<ans[i]<<endl;
        temp = ans[i];
    }

    return 0;
}

