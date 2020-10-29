/*
SMART KEYPAD - I
You will be given a numeric string S. Print all the possible codes for S.

Following vector contains the codes corresponding to the digits mapped.

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

For example, string corresponding to 0 is " " and 1 is ".+@$"


Input Format:
A single string containing numbers only.

Constraints:
length of string <= 10

Output Format:
All possible codes one per line in the following order.

The letter that appears first in the code should come first

Sample Input:
12
Sample Output:
.a
.b
.c
+a
+b
+c
@a
@b
@c
$a
$b
$c

*/

#include <iostream>
#include <cstring>
using namespace std;
string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
void phoneKeypad(char *inp,char *out,int i,int j)
{
    //Base case
    if(inp[i]=='\0')
    {
        out[j] = '\0';
        cout<<out<<"\n";
        return ;
    }

    //Rec case
    int r = inp[i]-'0';
    for(unsigned int k = 0; k< table[r].length() ;k++)
    {
        char ch = table[r][k];
        out[j] = ch;
        phoneKeypad(inp,out,i+1,j+1);
       
    }
    //cout<<endl;
}
int main() 
{
    char input[100];
    cin>>input;

    char output[100];
    phoneKeypad(input,output,0,0);
    return 0;
}

