/*
RECURSION-KEYPAD CODES
Take as input str, a string. str represents keys pressed on a nokia phone keypad. We are concerned with all possible words that can be written with the pressed keys.

Assume the following alphabets on the keys: 1 -> abc , 2 -> def , 3 -> ghi , 4 -> jkl , 5 -> mno , 6 -> pqrs , 7 -> tuv , 8 -> wx , 9 -> yz

E.g. “12” can produce following words “ad”, “ae”, “af”, “bd”, “be”, “bf”, “cd”, “ce”, “cf”

a. Write a recursive function which returns the count of words for a given keypad string. Print the value returned.

b.Write a recursive function which prints all possible words for a given keypad string (void is the return type for function).


Input Format:
Enter a number

Constraints:
None

Output Format:
Display the total no. of words and display all the words in a space separated manner

Sample Input:
12
Sample Output:
ad ae af bd be bf cd ce cf
9
Time Limit: 4 sec
*/
#include <iostream>
#include <cstring>
using namespace std;

string keypad[] = {"","abc","def","ghi","jkl","mno","pqrs","tuv","wx","yz"};

int count = 0 ;

void keypadCode(string inp,string out,int i) {
    //Base case
    if(i==inp.size()) {
        cout<<out<<" ";
        count++;
        return ;
    }

    //Rec case
    int r = inp[i] - '0';
    for(int k = 0;k < keypad[r].size() ;k++) {
        char ch = keypad[r][k];
        keypadCode(inp,out+ch,i+1);
    }
}
int main() 
{
    string inp;
    cin >> inp;
    string output;
    keypadCode(inp,output,0);
    cout << endl << count ;
    return 0;
}

