/*
Queue using two stacks 
DEQUEUE EFFICIENT QUEUE USING STACK
Implement a Queue using two stacks Make it Dequeue efficient.


Input Format:
Enter the size of the queue N add 0 - N-1 numbers in the queue

Output Format:
Display the numbers in the order they are dequeued and in a space separated manner

Sample Input:
5
Sample Output:
0 1 2 3 4
*/
#include <iostream>
#include <stack>
using namespace std;
class QueueUsingTwoStacks {
    private :
        stack<int> s1,s2;
    public :
        QueueUsingTwoStacks(int n = 5) {
            for(int i=0;i<n;i++){
                push(i);
            }
        }
        void push(int n){
            while(!s1.empty()){
                int x = s1.top();
                s1.pop();
                s2.push(x);
            }
            s1.push(n);
            while(!s2.empty()){
                int x = s2.top();
                s2.pop();
                s1.push(x);
            }
        }
        void pop(){
            s1.pop();
        }
        int top(){
            return s1.top();
        }
        bool empty(){
            return s1.empty();
        }
};
int main() {
    int n ; 
    cin>>n;
    QueueUsingTwoStacks q(n) ;
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }






    return 0;
}

