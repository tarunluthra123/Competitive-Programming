/*
Given an integer 'n'. Print all the possible pairs of 'n' balanced parentheses.
The output strings should be printed in the sorted order considering '(' has higher value than ')'.


Input Format:
Single line containing an integral value 'n'.

Constraints:
1<=n<=11

Output Format:
Print the balanced parentheses strings with every possible solution on new line.

Sample Input:
2
Sample Output:
()() 
(()) 


Sample Input:
3
Sample Output:
()()()
()(())
(())()
(()())
((()))
*/

#include <iostream>
using namespace std;
void generate(char s[],int n,int x,int y,int i)
{
    //Base case
    if(x==n && y==n)
    {
        s[i] = '\0';
        cout<<s<<endl;
        return ;
    }

    //Recursive cases
    if(y<x)
    {
        s[i] = ')';
        generate(s,n,x,y+1,i+1);
    }
    if(x<n)
    {
        s[i] = '(';
        generate(s,n,x+1,y,i+1);
    }
}
int main() 
{
    int n;
    cin>>n;
    char s[50];
    generate(s,n,0,0,0);
    return 0;
}

