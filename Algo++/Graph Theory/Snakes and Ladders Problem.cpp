/*
SNAKE AND LADDERS BOARD (BFS)
Given a snake and ladder board, find the minimum number of dice throws required to reach the destination or last cell from source or 1st cell. The player has total control over outcome of dice throw and wants to find out minimum number of throws required to reach last cell.


Input Format:
First line contains integer t as number of test cases. Each test case contains following input. First line contains three integers n, l, s which represents the number of cell of board, number of ladders and number of snakes. Following l lines contains the description of ladders and next s lines contains description of snakes.

Image

Constraints:
1 < t < 20
1< n,l,s < 50

Output Format:
For each test case you have to print the number which is equal to the minimum number of dice throws to reach the last cell.

Sample Input:
1
30 4 4
3 22
5 8
11 26
20 29
17 4
19 7
21 9
27 1
Sample Output:
3
Explanation:
Player start from the first cell. It goes to 1st 3 (then reach at 22) and then 28 and then 30. Total number of dice thrown is 3.
*/
#include <bits/stdc++.h>
using namespace std;

#define pb push_back

class SnakesAndLadder{
private :
    int n;  //Size of board
    map<int, list<int> > adjList ;
public :
    SnakesAndLadder(){}

    void addEdge(int u,int v){
        adjList[u].pb(v);
       // adjList[v].pb(u);
    }

    int solveGame(int src,int dest){
        queue<int> q ;
        map<int,int> dist;
        map<int,int> parent; 
        q.push(src);
        for(auto i : adjList){
            dist[i.first] = INT_MAX ;
        }
        dist[src] = 0 ;
        parent[src] = 0 ;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int child : adjList[node]){
                if(dist[child] == INT_MAX){
                    q.push(child);
                    dist[child] = dist[node] + 1 ;
                    parent[child] = node ;
                }
            }
        }


        return dist[dest] ;
    }

    void printAdjList(){
        for(auto i : adjList){
            cout << i.first << " -> ";
            for(auto j : i.second){
                cout << j << " ";
            }
            cout << endl ;
        }
    }

};

int main() {
    int testCases;
    cin >> testCases;
    while(testCases--){
        int n ; //Size pf board
        cin >> n;
        SnakesAndLadder g ;

        int ladders ;   //No of ladders on the board
        cin >> ladders;

        int snakes ;    //No of snakes on the board
        cin >> snakes ; 

        int board[n] = {0};
        pair<int,int> p ;
        for(int i=0;i<ladders;i++){
            cin >> p.first >> p.second ;
            board[p.first] = p.second-p.first ;
        }
        for(int i=0;i<snakes;i++){
            cin >> p.first >> p.second ;
            board[p.first] = p.second-p.first ;
        }

        //for(int i=0;i<n;i++){            cout << "board["<<i<<"] = "<<board[i] << endl ;        }

        for(int u=0;u<n;u++){
            //At every node , you can throw a dice 
            for(int dice=1;dice<=6;dice++){
                int v = u + dice + board[u+dice];
                if(v>=n || v<0) //Overflow condition
                    v = n-1;
                g.addEdge(u,v);
            }
        }

       // g.printAdjList() ; 

        cout << g.solveGame(0,n-1) << endl ;
    }


    return 0;
}

