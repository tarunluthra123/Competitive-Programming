/*
RECURSION-DICTIONARY ORDER(LARGER)
Take as input str, a string. Write a recursive function which prints all the words possible by rearranging the characters of this string which are in dictionary order larger than the given string


Input Format:
Enter a string

Constraints:
None

Output Format:
Display all the words larger than the string entered in separate lines

Sample Input:
cab

Sample Output:
cba
*/
#include <bits/stdc++.h>
using namespace std;
string s;
void permute(string inp,int i) {
    //Base case
    if(i == inp.size())  {
        if(inp > s){
            cout<<inp<<endl;
        }
        return ;
    }

    //Recursive case
    for(int j=i;j<inp.size();j++) {
        swap(inp[i],inp[j]);
        permute(inp,i+1);
    }
}

int main() {
    string str ;
    cin>>str;
    s=str;
    permute(str,0);

    return 0;
}
