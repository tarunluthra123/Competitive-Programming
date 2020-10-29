/*
BFS - SHORTEST PATH
Consider an undirected graph consisting of 'n' nodes where each node is labeled from 1 to n and the edge between any two nodes is always of length 6 . We define node 's' to be the starting position for a BFS.

Given 'q' queries in the form of a graph and some starting node, 's' , perform each query by calculating the shortest distance from starting node 's' to all the other nodes in the graph. Then print a single line of n-1 space-separated integers listing node s's shortest distance to each of the n-1 other nodes (ordered sequentially by node number); if 's' is disconnected from a node, print -1 as the distance to that node.


Input Format:
The first line contains an integer,q , denoting the number of queries. The subsequent lines describe each query in the following format:

Each line contains N and M, the number of nodes and edges respectively.

The next m lines contains u and v means that there is edge between u and v .

The last line contains 's', the starting node.

Constraints:
1 <= q <= 10
2 <= n <= 1000
1 <= m <= (n*(n-1))/2
1 <= u,s,v <= n

Output Format:
You have to print n-1 integer denoting the shortest distance from s to all other nodes excluding s itself.

Sample Input:
2
4 2
1 2
1 3
1
3 1
2 3
2
Sample Output:
6 6 -1
-1 6
Time Limit: 3 sec
*/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back

class Graph {
private :
    int V;
    map<int , list<int> > m ;   //Adjacency list <node,LL of neighbours>
    list<int> *l ; 
public :
    Graph(int n=4){
        V = n;
        l = new list<int>[V] ; 
    }
    void addEdge(int u,int v){
        l[u].pb(v);
        l[v].pb(u);
    }

    void printAdjList(){
        for(int i=0 ;i<V ; i++){
            cout << i << " -> ";

            //for(int i=1;i<=V;i++){
            for(auto element: l[i]){
             //   int element = l[i] ; 
                cout << element <<", ";
            }

            cout << endl ;
        }
    }

    void bfsShortestPath(int source){
        queue<int> q ;          //Queue for traversing level by level
        map<int,int> dist ;     //Distances from source node stored as <node,distance from src>
        map<int,int> parent ;   //To store the parent of each node as <node,parent>
        q.push(source);

        for(int i=0;i<V;i++){
            dist[i] = INT_MAX ;
        }
        dist[source] = 0;
        parent[source] = source ;

        while(!q.empty()){
            int node = q.front() ; 
            q.pop() ; 
            for(int child : l[node]){
            //for(int i=1;i<=V;i++){
              //  int child = 
                if(dist[child] == INT_MAX){
                    q.push(child);
                    dist[child] = dist[node] + 1;
                    parent[child] = node ; 
                }
            }
        }

        //Print the distances 
        for(int i=0;i<V;i++){
            if(dist[i] == INT_MAX){
                cout << "-1 ";
            }
            else if(dist[i] == 0){   
                //Skip the source node           
            }
            else {
                cout << 6*dist[i] << " ";
            }
        }


    }

};



int main() {
    int queries ;
    cin >> queries ; 
    while(queries--){
        int n , e;
        cin >> n;   //No of nodes
        cin >> e;   //No of edges
        Graph g(n);
        

        //Subtracting 1 from node values while passing to the graph as we are using 0 to n-1 indexing in the graph
        //And the problem uses to 1 to n indexing
        for(int i=0;i<e;i++){
            int u,v;
            cin >> u >> v;
            g.addEdge(u-1,v-1);
        }
        //g.printAdjList() ; 
        int source ; 
        cin >> source ;
        g.bfsShortestPath(source-1);
        cout << endl;
    }



    return 0;
}

