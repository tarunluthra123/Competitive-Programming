/*
Reverse a Stack using Recursion.


Input Format:
First line contains an integer N (size of the stack). Next N lines follow each containing an integer to be stored in the stack where the last integer is at the top of the stack.

Output Format:
Output the values of the reversed stack with each value in following line.

Sample Input:
3
3
2
1
Sample Output:
3
2
1
Time Limit: 4 sec
*/
#include <iostream>
#include <stack>
using namespace std;
void insertAtBottom(stack<int> &s,int x){
    if(s.empty()){
        s.push(x);
        return ;
    }
    int y = s.top();
    s.pop();
    insertAtBottom(s,x);
    s.push(y);
}

void reverseStackRec(stack<int> &s){
    if(s.empty()){
        return ;
    }

    int x = s.top();
    s.pop();
    reverseStackRec(s);
    insertAtBottom(s,x);
}
int main() {
    stack<int> s;
    int n ;
    cin>>n;
    for(int i=0;i<n;i++){
        int x ;
        cin>>x;
        s.push(x);
    }
    reverseStackRec(s);
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();

    }
    
    return 0;
}

