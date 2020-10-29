/*
PATTERN TRIANGLE
Take N (number of rows), print the following pattern (for N = 4).

                       1 
                     2 3 2
                   3 4 5 4 3
                 4 5 6 7 6 5 4

Constraints:
0 < N < 10

Sample Input:
4
Sample Output:
                        1
		2	3	2
	3	4	5	4	3
4	5	6	7	6	5	4
Explanation:
Each number is separated from other by a tab.
*/
#include <iostream>
using namespace std;
int main() {
    int n ;
    cin >> n;

    int space = n -1 ;
    for(int i=1;i<=n;i++){
        for(int j=0;j<space;j++){
            cout << "\t";
        }
        space -- ;
        bool up = true ;
        for(int j=i ; j>=i ;){
            cout << j << "\t";
            
            if(j == 2*i -1){
                up = false ;
            }
            if(up){
                j++;
            }
            else {
                j--;
            }
        }
        cout << endl;
    }



    return 0;
}

