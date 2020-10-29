/*
MAPPED STRINGS
We are given a hashmap which maps all the letters with number. Given 1 is mapped with A, 2 is mapped with B…..26 is mapped with Z. Given a number, you have to print all the possible strings.


Input Format:
A single line contains a number.

Constraints:
Number is less than 10^6

Output Format:
Print all the possible strings in sorted order in different lines.

Sample Input:
123
Sample Output:
ABC
AW
LC
Explanation:
'1' '2' '3' = ABC '1' '23' = AW '12' '3' = LC

Time Limit: 1 sec
*/

#include <bits/stdc++.h>
using namespace std;

void mappedStrings(string inp, string out)
{
    if (inp.size() == 0)
    {
        cout << out << endl;
        return;
    }

    int singleDigitNumber = inp[0] - '0'; // = stoi(inp.substr(0,1));

    char ch = singleDigitNumber + 'A' - 1;
    string ros = inp.substr(1);
    mappedStrings(ros, out + ch);

    if (inp.size() >= 2)
    {
        int doubleDigitNumber = stoi(inp.substr(0, 2)); // singleDigitNumber*10 + (s[1]-'0');
        ch = doubleDigitNumber + 'A' - 1;

        ros = inp.substr(2);

        mappedStrings(ros, out + ch);
    }
}

int main()
{
    string num;
    cin >> num;

    mappedStrings(num, "");

    return 0;
}

