/*
Jack is awesome. His friends call him little Einstein. To test him, his friends gave him a string.
They told him to add the string with its reverse string and follow these rules:

Every ith character of string will be added to every ith character of reverse string.
Both string will contain only lower case alphabets(a-z).
Eg:- a+a=b,a+c=d,z+a=a (Refer to sample test cases for more details)
Input:

First line contains a value N denoting number of test cases. Next N lines contains string str.

Output:

For every string str output the string that Jack's friends wants from him.

Constraints

1 <= N <= 10

1 <= str <= 10^5

SAMPLE INPUT
4
hello
codeapocalypse
programming
world


SAMPLE OUTPUT
wqxqw
hhtdmqrrqmdthh
wfxtebetxfw
aajaa
*/


#include <stdio.h>
#include <string.h>
int main()
{
    char s[1000000];
    int a, b, t, sum, m;
    long int i;
    long int l;
    l = 0;
    scanf ("%d", &t);

    for (m = 0; m < t; m++)
    {
        s[100005] = '\0';
        scanf ("%s", s);
        l = strlen (s);
        a = 0;
        b = 0;

        for (i = 0; i < l; i++)
        {
            a = s[i] - 96;
            b = s[l - i - 1] - 96;
            sum = a + b;

            if (sum > 26 && sum != 52)
                sum = sum - 26;

            if (sum == 52)
                sum = 26;

            sum = sum + 96;
            printf ("%c", sum);
            sum = 0;
        }

        printf ("\n");
    }

    return 0;
}
