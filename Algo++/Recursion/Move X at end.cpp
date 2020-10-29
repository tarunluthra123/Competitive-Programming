/*
MOVE ALL X AT END
Take as input str, a string. Write a recursive function which moves all ‘x’ from the string to its end. E.g. for “abexexdexed” return “abeedeedxxx”. Print the value returned


Input Format:
Enter the string

Constraints:
None

Output Format:
Display the string with all x's moved at the end

Sample Input:
axbxa
Sample Output:
abaxx
*/


#include <bits/stdc++.h>
using namespace std;

string move(string s)
{
    if (s.size() <= 1)
        return s;

    string ros = s.substr(1);
    ros = move(ros);
    if (s[0] == 'x')
        return ros + s[0];
    else
        return s[0] + ros;
}

int main()
{
    string s;
    cin >> s;

    cout << move(s);

    return 0;
}

