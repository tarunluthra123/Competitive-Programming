/*
Program to obtain the current_min element from a stack in O(1) time and O(1) space

Input Format :
Take as input a series of queries till -1.
If query == 1 , take another integer as input and push it into the stack
If query == 2 , pop an element from the stack
If query == 3 , print the current_min value

Output Format :
Print the current_min value for each query 2 in new line.
*/
#include <iostream>
#include <stack>
using namespace std;
int main() {
    stack<int> s;
    int currentMin = 0;
    int q = 0; 
    while(q != -1){
        cin >> q;
        if(q == 1) {
            //Query to push new element
            int x; 
            cin >> x;
            if(s.empty()){
                currentMin = x;
                s.push(x);
            }
            else if(x >= currentMin) {
                s.push(x);
            }
            else {
                int temp = 2*x - currentMin ;
                s.push(temp);
                currentMin = x;
            }
        }
        else if(q==2){
            //Query to pop an element from the stack
            if(s.empty()) {
                cout << "Stack is empty" << endl;
                continue;
            }
            int y = s.top();
            if(y >= currentMin) {
                s.pop();
            }
            else {
                currentMin = 2*currentMin - y;
                s.pop();
            }
        }
        else if(q == 3) {
        	//Query to print the current_min element
            if(s.empty()){
                cout << "Stack is empty" << endl ;
            }
            else {
                cout << currentMin << endl;
            }
        }
    }


    return 0;
}

