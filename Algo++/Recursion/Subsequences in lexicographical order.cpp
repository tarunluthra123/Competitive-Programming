/*
RECURSION - ALL SUBSEQUENCES
Print all the subsequences of a string in lexicographical order.


Input Format:
First line contains an integer N, the no of strings.
Next, N lines follows one string per line.

Constraints:
1 < len(str) < 20

Output Format:
No of subsequences one per line

Sample Input:
1  
ab
Sample Output:
  
a  
ab  
b  
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int k = 0;
string s[100];
void subsequences(char *inp,char*out,int i,int j)
{
    //Base case
    if(inp[i]=='\0')
    {
        out[j] = '\0';
        s[k++] = out;
        return ;
    }

    //Recursive case
    //1. Include the current character
    out[j] = inp[i];
    subsequences(inp,out,i+1,j+1);

    //2. Exclude the current character
    subsequences(inp,out,i+1,j);
}
int main() 
{
    int testCases;
    cin>>testCases;
    while(testCases--)
    {
        char input[100] ;
        char output[100];
        cin>>input;
        k = 0;
        subsequences(input,output,0,0);
        int  l = strlen(input);
        int limit = (1<<l) ;
        sort(s,s+limit);
        for(int i =0;i<limit;i++)
            cout<<s[i]<<endl;

    }
    


    return 0;
}

