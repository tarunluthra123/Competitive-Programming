/*
PLAYING WITH CARDS (IN STACK)
You are at a casino. There are N stacked cards on pile . Each card has a number written on it. Then there will be Q iterations. In ith iteration, you start picking up the cards in Ai-1th pile from the top one by one and check whether the number written on the card is divisible by the ith prime number. If the number is divisible, you stack that card on pile Bi. Otherwise, you stack that card on pile Ai. After Q iterations, cards can only be on pile B1, B2, B3, . . . BQ, AQ . Output numbers on these cards from top to bottom of each piles in order of B1, B2, B3, . . . BQ, AQ .


Input Format:
First line contains N and Q. The next line contains N space separated integers representing the initial pile of cards i.e., A0. The leftmost value represents the bottom plate of the pile.

Constraints:
N < 10^5

Output Format:
Output N lines, each line containing the number written on the card.

Sample Input:
5 1
3 4 7 6 5
Sample Output:
4
6
3
7
5
Explanation:
Initially:

A0 = [3, 4, 7, 6, 5]<-TOP

After 1st iteration:

A0 = []<-TOP

A1 = [5, 7, 3]<-TOP

B1 = [6, 4]<-TOP

Now first print B1 from top to bottom then A1 from top to bottom.
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 1299709         //10^5 th prime number

bool sieve[MAX];
vector<int> primes;

void createSieve(){
    for(long i=0;i<MAX;i++){
        sieve[i] = true;
    }
    sieve[0] = sieve[1] = false;
    for(long i=2;i<MAX;i++){
        if(sieve[i]){
            primes.push_back(i);
            for(long j=i*i;j<MAX;j+=i){
                sieve[j] = false;
            }
        }
    }
}


int main() {
    primes.push_back(1);     //Putting 1 as 0th prime number (even though its not)
    createSieve();

    int n,q;
    cin >> n >> q;
    int size = q+1;
    stack<int> a[size];
    stack<int> b[size];
    while(n--){
        int x;
        cin >> x;
        a[0].push(x);
    }
    int i=1;
    while(q--){
        while(!a[i-1].empty()){
            int topElement = a[i-1].top();
            a[i-1].pop();
            if(topElement % primes[i] == 0){
                b[i].push(topElement);
            }
            else {
                a[i].push(topElement);
            }
        }
        i++;
    }

    /*
    for(int i=0;i<size;i++){
        cout << "a["<<i<<"] = ";
        while(!a[i].empty()){
            cout << a[i].top() << " ";
            a[i].pop();
        }
        cout << endl;
    }
    for(int i=0;i<size;i++){
        cout << "b["<<i<<"] = ";
        while(!b[i].empty()){
            cout << b[i].top() << " ";
            b[i].pop();
        }
        cout << endl;
    }
    */

    //Print b stacks first ...then a stacks
    for(int i=0;i<size;i++){
        while(!b[i].empty()){
            cout << b[i].top() << endl;
            b[i].pop();
        }
    }
    for(int i=0;i<size;i++){
        while(!a[i].empty()){
            cout << a[i].top() << endl;
            a[i].pop();
        }
    }


    return 0;    
}

