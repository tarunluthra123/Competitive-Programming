/*
https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/bit-flippings-dd1f7ef1/

Bit Flipping Game
Two players A and B are playing a game.They are given  binary numbers as input. Each binary number is represented as a string of
characters '0' or '1'. The string always ends at '1'.  In one move each player decides a bit position  . Then he visits all the
numbers and if their bit at that position is '1' then he changes it to '0'. It is mandatory to flip(change '1' to '0') bit of atleast one number in each move. The player who is unable to make a move loses. Player A begins the game.

Input
First line contains a number N as input. Next N lines contain a binary string each.

Output
Print A if player A wins , B otherwise. In the next line print the move number of the last move of the winning player.

Constraints
1<=N<=10^5
1<=|S|<=10^6 , |S| where  is sum of length of all bit strings.

SAMPLE INPUT
2
01
001
SAMPLE OUTPUT
B
2

Explanation
First string in the input is 01 so its 0th bit is 0 and 1st bit is 1. Rest all the bits are zero

Second string in the input is 001 , its 0th bit is 0 , 1st bit is also 0 and second bit is 1. Rest all the bits are zero.

First move : Player A selects the bit position 1. So first string becomes 00 and second string is 001

Second move: Player B selects the bit position 2. So first string remains 00 and second becomes 000.

Now the turn is of player A but there are no numbers which have '1' in it's binary representation so A loses and B wins. Also the last move played by the player B is 2. Hence the move number is 2.

*/


#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    long n, i, maxLength, l;
    string s[100000];
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> s[i];
        l = s[i].size();
        maxLength = max (maxLength, l);
    }

    long count = 0;

    for (unsigned long j = 0; j < maxLength; j++)
    {
        for (i = 0; i < n; i++)
        {
            if (j >= s[i].size() )
                continue;                    //continue for i loop

            if (s[i][j] == '1')
            {
                count++;
                break;                   //continue for j loop
            }
        }
    }

    if (count & 1)
        cout << 'A';
    else
        cout << 'B';

    cout << endl << count;


    return 0;
}
