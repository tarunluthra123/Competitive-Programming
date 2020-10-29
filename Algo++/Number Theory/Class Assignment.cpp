/*
In a mathematics class, Teacher ask Alice to find the number of all n digit distinct integers which is formed by the two distinct digits ai and bi but there is a rule to form n digit integer.

Rule: She has to form n digit integer by using two digits ai and bi without consecutive bi.

Alice is very weak in maths section. Help her to find the number of such n digit integers.


Input Format:
The first line contains T, the number of test cases. Further T lines contains the value n which is the number of digit in the integer.

Constraints:
1<=T<=40
1<=n<44

Output Format:
For each test case print the number of such n digit integer.

Sample Input:
3
1
2
3
Sample Output:
#1 : 2
#2 : 3
#3 : 5
Explanation:
For n=1 : integers = a, b . For n=2 : integers = aa, ab, ba For n=3 : integers = aaa, aab, aba, baa, bab
*/


#include <iostream>
#define ull unsigned long long
using namespace std;

ull fib[45];
void createFibonnaci(){
    fib[0] = 1;
    fib[1] = 2;
    fib[2] = 3;
    fib[3] = 5;
    for(int i=4;i<=44;i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
}

int main() 
{
    createFibonnaci();
    ull testCases;
    cin>>testCases;
    ull i = 0 ;
    while(testCases--)
    {
        i++;
        ull n;
        cin>>n;
        cout<<"#"<<i<<" : "<<fib[n]<<endl;
    }

    return 0;
}

