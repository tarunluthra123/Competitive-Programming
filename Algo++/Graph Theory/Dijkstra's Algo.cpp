/*
DIJKSTRA'S ALGORITHM
Given a graph consisting 'N' nodes (labeled 1 to N) where a specific given node 'S' represents the starting position and an edge between two nodes is of a given length, which may or may not be equal to other lengths in the graph.

It is required to calculate the shortest distance from the start position (Node 'S') to all of the other nodes in the graph.

If a node is unreachable, the distance is assumed as -1.


Input Format:
The first line contains T, denoting the number of test cases. First line of each test case has two integers N, M denoting the number of nodes in the graph and, denoting the number of edges in the graph.

The next M lines each consist of three space-separated integers x,y,r where x and y denote the two nodes between which the undirected edge exists, 'r' denotes the length of edge between these corresponding nodes.

The last line has an integer, 'S' denoting the starting position.

Constraints:
1 <= N <= 3000
1 <= M <= (N*(N-1))/2
1 <= x,y <= N
1 <= r <= 10^5

Output Format:
For each of the T test cases, print a single line consisting N-1 space separated integers denoting the shortest distance of N-1 nodes other than from starting position S in increasing order of their labels.

For unreachable nodes, print -1.

Sample Input:
1
4 4
1 2 24
1 4 20
3 1 3
4 3 12
1

Sample Output:
24 3 15
Time Limit: 2 sec
*/
#include <bits/stdc++.h>
using namespace std;

#define pb push_back

class Graph {
private :
    unordered_map<int, list< pair<int,int> > >m;    //Adjacency List of <vertex , <neighbour,weight of edge> >
public :
    Graph(int V){
        for(int i=1;i<=V;i++){
            m[i];
        }
    }

    void addEdge(int u,int v,int w){
        m[u].pb(make_pair(v,w));
        m[v].pb(make_pair(u,w));
    }

    void dijkstraAlgo(int source){
        map<int,int> dist ;   //To store distances of vertices from source as <vertex,distance from src>
        //Set all distances to infinity
        for(auto i : m){
            dist[i.first] = INT_MAX  ;
        }
        dist[source] = 0;

        set< pair<int,int> > s; //Set to find the node with min distance value as it stores in order storing as <dist,parentNode>

        s.insert(make_pair(0,source)) ;

        while(!s.empty()){
            //Find the pair at the front
            pair<int,int> p = *(s.begin());

            int node = p.second ; 
            int nodeDist = p.first; //Distance of node from source

            s.erase(s.begin());

            //Iterate over neighbours/children of node
            for(auto childPair : m[node]){
                if(nodeDist + childPair.second < dist[childPair.first]){
                    //Update the node
                    int dest = childPair.first ;
                    auto f = s.find(make_pair(dist[dest],dest));
                    if(f != s.end()){
                        s.erase(f);
                    }

                    //Insert new pair
                    dist[dest] = nodeDist + childPair.second ;
                    s.insert(make_pair(dist[dest],dest));
                }
            }
        }


        //Print all distances except for the source itself 
        for(auto d:dist){
            if(d.second == INT_MAX){
                cout << "-1 " ;
            }
            else if(d.second == 0){
                //Skip the source itself 
            }
            else {
                cout << d.second << " ";
            }
        }


    }


    void printAdjList(){
        for(auto j:m){
            cout << j.first << " -> ";

            for(auto l:j.second){
                cout << "("<<l.first<<","<<l.second<<") ";
            }

            cout << endl ;
        }
    }

};



int main() {
    int testCases;
    cin >> testCases;
    while(testCases--){
        int V,e;
        cin >> V >> e;
        
        Graph g(V);

        for(int i=0;i<e;i++){
            int u,v,w;
            cin >> u >> v >> w;
            g.addEdge(u,v,w);
        }

        int source ;
        cin >> source ; 

        //g.printAdjList() ; 

        g.dijkstraAlgo(source);
        cout << endl ;        

    }




    return 0;
}

