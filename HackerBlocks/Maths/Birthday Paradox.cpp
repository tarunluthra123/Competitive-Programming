/*
Birthday Paradox
Your task is simple, determine the minimum number of people required in the room so that two have same birthday with probability greater than or equal to 'p'. (Assume there are 365 days in every year)

Input Format
Single line containing the given probability.

Constraints
0<p<=1

Output Format
Print an integral value denoting minimum number of people.

Sample Input
0.5
Sample Output
23
*/

#include <iostream>
#include <cmath>
using namespace std;
int main() {
    float p ;
    cin >> p;
    if(p==1) {
        cout << 366;
    }
    else {
        cout << ceil(sqrt(2*365*log(1/(1-p)))); 
    }
	return 0;
}
