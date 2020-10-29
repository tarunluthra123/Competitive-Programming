/*
REMOVE DUPLICATES CHARACTERS
Take as input str, a string. Write a recursive function which returns a new string in which all duplicate consecutive characters are reduced to a single char. E.g. for “hello” return “helo”. Print the value returned.


Input Format:
Enter the string

Constraints:
None

Output Format:
Display the resulting string

Sample Input:
hello
Sample Output:
helo

*/



#include <iostream>
using namespace std;
void removeDuplicate(char *s)
{
    //Base case
    if(s[1]=='\0')
        return ;

    //Rec case
    if(s[0]==s[1])
    {
        for(int i=0;s[i]!='\0';i++)
        {
            s[i] = s[i+1];
        }
        removeDuplicate(s);
    }
    removeDuplicate(++s);
}
int main() 
{
    char s[100];
    cin>>s;
    removeDuplicate(s);
    cout<<s;
    return 0;
}

